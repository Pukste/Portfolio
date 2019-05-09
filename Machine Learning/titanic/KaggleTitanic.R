Ttrain <- read.csv("train.csv")
Ttest <- read.csv("test.csv")

#inspecting data
summary(Ttrain)

str(Ttrain)

#checking train data for missing values
colnames(Ttrain)[apply(Ttrain, 2, anyNA)]

#age has missing values, let's replace them with mean

average_age <- mean(Ttrain$Age, na.rm = TRUE)

average_age

Ttrain[is.na(Ttrain)] <- average_age

#checking the test data for missing values
colnames(Ttest)[apply(Ttest, 2, anyNA)]
average_test_age <- mean(Ttest$Age, na.rm = TRUE)
average_fare <- mean(Ttest$Fare, na.rm = TRUE)

Ttest$Age[is.na(Ttest$Age)] <-average_test_age
Ttest$Fare[is.na(Ttest$Fare)] <- average_fare

#removing names from train and test
Train <- subset(Ttrain, select = -c(Name)) 
Test <- subset(Ttest, select = -c(Name))
#install.packages("ranger")
library("ranger")

Titanic.model <- ranger(Survived ~ ., data=Train, num.trees = 2000)




Submission <- data.frame(PassengerId=Ttest$PassengerId)

Survived <- predict(Titanic.model, Test)

Submission$Survived <- round(Survived$predictions)

CrossTable(x = result$Survived, y= Submission$Survived, prop.chisq = F)

#write.csv(Submission,'submission.csv', row.names = FALSE)