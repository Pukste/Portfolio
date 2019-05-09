# Tehtävä 1

credit<-read.csv("credit.csv")
str(credit)


install.packages("fastDummies")
library("fastDummies")

credit <- fastDummies::dummy_cols(credit)
credit <- credit[, c(-1,-3,-4,-6,-7,-11,-12,-14,-16,-46,-47)]
credit_labels <- credit$default


normalize <- function(x){
  return ((x-min(x))/ (max(x)-min(x)))
}

str(credit)

summary(credit_labels)

# Tehtävä 2

credit_train <- credit[1:900,]
credit_test <- credit[901:1000,]
credit_train_labels <- credit_labels[1:900]
credit_test_labels <- credit_labels[901:1000]

library(class)

credit_test_predicted <- knn(train = credit_train, test= credit_test, cl = credit_train_labels, k=30)

# Tehtävä 4

install.packages("gmodels")
library(gmodels)

CrossTable(x= credit_test_labels, y= credit_test_predicted, prop.chisq = FALSE)

# a) kaksi kertaa

# b) ei kertaakaan

# c) knn sai 98/100 oikein, tunnilla sain 60/100, joten erittäin paljon parempia