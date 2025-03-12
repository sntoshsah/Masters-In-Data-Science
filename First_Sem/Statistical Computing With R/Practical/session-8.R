#install.packages("DBI")
#install.packages("dbplyr")
#install.packages("tidyverse")
library(DBI)
library(dbplyr)
library(tidyverse)

#install.packages("nycflights13")
library("nycflights13")

flights
jan1<-filter(flights,month==1 , day==1)
jan1
(jan1<-filter(flights, month==1, day==1))
jan1




summarise(flights, delay=mean(dep_delay, na.rm=TRUE))
summarise(flights, delay=sd(dep_delay, na.rm = TRUE))
summarise(flights, delay=median(dep_delay, na.rm = TRUE))

hist(delay)
hist(flights$dep_delay)

## Group By
by_day<-group_by(flights, year, month, day)
summarise(by_day, delay=mean(dep_delay, rm.na=TRUE))

## Multiple Operations: pipes
delays<-flights%>%
  group_by(dest)%>%
  summarise(
    count=n(),
    dist=mean(arr_delay,na.rm=TRUE)
    %>%
      filter(count>20, dest !="HNL")
  )


not_cancelled<- flights%>%
  filter(!is.na(dep_delay),!is.na(arr_delay))
not_cancelled%>%
  group_by(year,month,day)%>%
  
  
delays<-not_cancelled%>%
  group_by(tailnum)%>%
  summarise(
    delay=mean(arr_delay)
    
hist(delays$delay)
  )