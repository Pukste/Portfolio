wbcd <- read.csv("wisc_bc_data.csv")
wbcd <- wbcd[,-1]
wbcd_train <- wbcd[1:469,]
wbcd_test <- wbcd[470:569,]
wbcd_test_labels <- wbcd_test$diagnosis

# Teht�v� 1


install.packages("rpart")
library(rpart)

wbcd.rpart.model <- rpart(diagnosis ~ ., data=wbcd_train)


wbcd.rpart.model
summary(wbcd.rpart.model)

printcp(wbcd.rpart.model)

plot(wbcd.rpart.model, uniform = T, branch = 0.6, margin = 0.1)
text(wbcd.rpart.model, all = T, use.n = T)

predictions <- predict(wbcd.rpart.model, wbcd_test, type="class")
library(gmodels)
CrossTable(x= wbcd_test$diagnosis, y= predictions, prop.chisq = FALSE)

# yksi hyv�nlaatuinen luokiteltiin pahanlaatuiseksi ja viisi pahanlaatuista hyv�nlaatuiseksi
# eli 94%, mutta koska kyseess� on sy�p�, ei kovin hyv�

# Teht�v� 2

install.packages("ranger")
library("ranger")

wbcd.rf.model <- ranger(diagnosis ~ ., wbcd_train, num.trees = 1000)
predictions.rf <- predict(wbcd.rf.model, wbcd_test)
CrossTable(x = wbcd_test$diagnosis, y= predictions.rf$predictions, prop.chisq = F)

# luokitteli yhden pahanlaatuisen hyv�nlaatuiseksi
# eli 99%, mutta huonompi juttu sille yhdelle