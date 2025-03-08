#install.packages("curl")
#install.packages("httr")
install.packages("rvest")
library(rvest)
simple<-read_html("https://dataquestio.github.io/web-scraping-pages/simple.html")
simple%>%
  html_nodes("p")%>%
  html_text()

tabel<-read_html("https://w3schools.com/html/html_tables.asp")
tabel%>%
  html_nodes("table")
  html_nodes("th")
  html_nodes("tr")
  html_nodes("td")
  html_table()

  
  
covid_html<-read_html("https://en.wikipedia.org/wiki/COVID-19_pandemic_in_Nepal")
str(covid_html)
  