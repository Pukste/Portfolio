// Tehtävä 1

install.packages("car")
library(car)
data(Quartet)

str(Quartet)

summary(Quartet)

// Tehtävä 2


plot(Quartet$x, Quartet$y1)


Quartet.model <- lm(y1~x, data=Quartet)
Quartet.model

summary(Quartet.model)



plot(Quartet$x, Quartet$y1) + abline(Quartet.model)

// Tehtävä 3

Quartet$predicted <- predict(Quartet.model)

ggplot(Quartet, aes(x=predicted, y=y1)) + geom_point() + geom_abline()

virhe <- Quartet$predicted - Quartet$y1
virhe2 <- virhe^2
rmse <- sqrt(mean(virhe2))
rmse

sd(Quartet$y1)

kor <- cor(Quartet$y1, Quartet$predicted)
kor

rss <- sum(virhe^2)
poikkeama <- Quartet$y1 - mean(Quartet$y1)
ss <- sum(poikkeama^2)
r2 <- 1 - (rss/ss)
r2

// Tehtävä 4





newdata <- data.frame(x = c(3,6,15))
newdata$y1 <- predict(Quartet.model, newdata = newdata)

