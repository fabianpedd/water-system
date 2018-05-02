


void testRTC() {
  Serial.print(second());
  Serial.print(',');
  Serial.print(minute());
  Serial.print(',');
  Serial.print(hour());
  Serial.print(" - ");
  Serial.print(day());
  Serial.print(',');
  Serial.print(month());
  Serial.print(',');
  Serial.print(year());
  Serial.println();   
}
bool checkTime(uint8_t _hour, uint8_t _minute) {
  if(_hour == (uint8_t) hour() && _minute == (uint8_t) minute()) {
    return true;
  } else {
    return false;
  }
}

void setSysTime() {
  current_minute = minute();
  current_hour = hour();
}
