

void init1() {
  //Serial
  Serial.begin(115200);
  while(!Serial) delay(1);
  Serial.println("--ok--");
  
  //Relai
  pinMode(relai_l, OUTPUT);
  digitalWrite(relai_l, HIGH);

  pinMode(relai_r, OUTPUT);
  digitalWrite(relai_r, HIGH);


  //Sonar
  DDRD &= ~(1<<snr_eco);
  DDRD |= (1<<snr_trg);
  PORTD &= ~(1<<snr_trg);

  DDRD &= ~(1<<snl_eco);
  DDRD |= (1<<snl_trg);
  PORTD &= ~(1<<snl_trg);

  
  //RTC Clock
  setSyncProvider(RTC.get);   
  if(timeStatus() != timeSet) {
      Serial.println("Unable to sync with the RTC");
      return(1);  
  } else {
      Serial.println("RTC has set the system time");
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

  delay(100);

  //Bluetooth
  blSerial.begin(38400);
  while(!blSerial) delay(1);
  blSerial.println("--ok--");

}

