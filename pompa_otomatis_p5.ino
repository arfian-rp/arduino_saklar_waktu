#include <DS3231.h>

DS3231  rtc(SDA, SCL);

void setup()
{
  pinMode(2,OUTPUT);
  Serial.begin(115200);
  rtc.begin();
  //rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(12, 0, 0);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(1, 1, 2014);   // Set the date to January 1st, 2014
}
int n = 0;
void loop()
{
  Serial.print(rtc.getTime().hour);
  Serial.print(" - ");
  Serial.println(rtc.getTime().min);
  if(rtc.getTime().min == 10){
    if(n == 0){
      digitalWrite(2,LOW);
      delay(60000);
      n += 1;
      digitalWrite(2,HIGH);
    }
  }else{
    digitalWrite(2,HIGH);
    n = 0;
  }
}
