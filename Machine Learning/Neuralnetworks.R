#Asetetaan siemenluku ja otetaan Boston dataset k�ytt��n
set.seed(500)
library(MASS)
data <- Boston


#varmistetaan ettei datapointteja puutu
apply(data,2,function(x) sum(is.na(x)))



#Splittaa data tehd��n lineaarinen regressio ja testataan
index <- sample(1:nrow(data),round(0.75*nrow(data)))
train <- data[index,]
test <- data[-index,]
lm.fit <- glm(medv~., data=train)
summary(lm.fit)
pr.lm <- predict(lm.fit,test)
MSE.lm <- sum((pr.lm - test$medv)^2)/nrow(test)



#normalisoidaan data ja splitataan train_iin ja test_iin
maxs <- apply(data, 2, max) 
mins <- apply(data, 2, min)
scaled <- as.data.frame(scale(data, center = mins, scale = maxs - mins))
train_ <- scaled[index,]
test_ <- scaled[-index,]

#otetaan neuralnet k�tt��n ja tehd��n neuralnet train_ datasta
install.packages("neuralnet")
library(neuralnet)
n <- names(train_)
f <- as.formula(paste("medv ~", paste(n[!n %in% "medv"], collapse = " + ")))
nn <- neuralnet(f,data=train_,hidden=c(5,3),linear.output=T)

#plotataan neuralnet
plot(nn)

#skaalataan data ja lasketaan MSE
pr.nn <- compute(nn,test_[,1:13])
pr.nn_ <- pr.nn$net.result*(max(data$medv)-min(data$medv))+min(data$medv)
test.r <- (test_$medv)*(max(data$medv)-min(data$medv))+min(data$medv)
MSE.nn <- sum((test.r - pr.nn_)^2)/nrow(test_)

#komparisoidaan lineaarista ja neuralnetwork MSE arvoja
print(paste(MSE.lm,MSE.nn))

# ristivalidoidaan plottaamalla tuloksen varmennusta varten
par(mfrow=c(1,2))
plot(test$medv,pr.nn_,col='red',main='Real vs predicted NN',pch=18,cex=0.7)
abline(0,1,lwd=2)
legend('bottomright',legend='NN',pch=18,col='red', bty='n')
plot(test$medv,pr.lm,col='blue',main='Real vs predicted lm',pch=18, cex=0.7)
abline(0,1,lwd=2)
legend('bottomright',legend='LM',pch=18,col='blue', bty='n', cex=.95)



# jatketaan validointia
plot(test$medv,pr.nn_,col='red',main='Real vs predicted NN',pch=18,cex=0.7)
points(test$medv,pr.lm,col='blue',pch=18,cex=0.7)
abline(0,1,lwd=2)
legend('bottomright',legend=c('NN','LM'),pch=18,col=c('red','blue'))


# ristivalidointia boot kirjaston kanssa/linear
install.packages("boot")
library(boot)
set.seed(200)
lm.fit <- glm(medv~.,data=data)
cv.glm(data,lm.fit,K=10)$delta[1]

# lis�� validointia/net
set.seed(450)
cv.error <- NULL
k <- 10
library(plyr) 
pbar <- create_progress_bar('text')
pbar$init(k)
for(i in 1:k){
  index <- sample(1:nrow(data),round(0.9*nrow(data)))
  train.cv <- scaled[index,]
  test.cv <- scaled[-index,]
  nn <- neuralnet(f,data=train.cv,hidden=c(5,2),linear.output=T)   
  pr.nn <- compute(nn,test.cv[,1:13])
  pr.nn <- pr.nn$net.result*(max(data$medv)-min(data$medv))+min(data$medv)   
  test.cv.r <- (test.cv$medv)*(max(data$medv)-min(data$medv))+min(data$medv)   
  cv.error[i] <- sum((test.cv.r - pr.nn)^2)/nrow(test.cv)    
  pbar$step()
}


#plotataan keski MSE ja tulokset blotboxissa.. cv.error on null?
mean(cv.error)
cv.error


boxplot(cv.error,xlab='MSE CV',col='cyan',
        border='blue',names='CV error (MSE)',
        main='CV error (MSE) for NN',horizontal=TRUE)
