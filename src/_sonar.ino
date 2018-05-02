
uint32_t leftWaterHeight() {
  uint32_t water_height = left_sonar_offset - distL(5);
  Serial.print("Left Water Height: ");
  Serial.println(water_height);
  return water_height;
}

uint32_t rightWaterHeight() {
  uint32_t water_height = right_sonar_offset - distR(5);
  Serial.print("Right Water Height: ");
  Serial.println(water_height);
  return water_height;
}

uint32_t distR(uint8_t itr) {
  uint16_t reverse = max_dist * 57;

  uint32_t sum_centi = 0;

  for(uint8_t i=0; i < itr; i++) {
    PORTD |= (1<<snr_trg);      //send pulse
    delayMicroseconds(10);
    PORTD &= ~(1<<snr_trg);
    
    while(!(PIND & (1<<snr_eco))) {     //wait for return pulse
      //Serial.print("low");;
    }
    
    uint32_t centi = micros();          //measure return pulse 
    while((PIND & (1<<snr_eco)) && ((micros() - centi) <= reverse)) {
      //Serial.print("high");;
    }
    centi = (((uint32_t)micros()) - centi) / (uint32_t)57;        //calculate distance
    //Serial.println(centi);
    
    sum_centi += centi;
    //Serial.print(i+1);
    delay(40);
   
  }

  sum_centi /= itr;
  //Serial.print("RIGHT: ");
  //Serial.println(sum_centi);
  
  return sum_centi;
}


uint32_t distL(uint8_t itr) {
  uint16_t reverse = max_dist * 57;

  uint32_t sum_centi = 0;

  for(uint8_t i=0; i < itr; i++) {
    PORTD |= (1<<snl_trg);      //send pulse
    delayMicroseconds(10);
    PORTD &= ~(1<<snl_trg);
    
    while(!(PIND & (1<<snl_eco))) {     //wait for return pulse
      //Serial.print("low");;
    }
    
    uint32_t centi = micros();          //measure return pulse 
    while((PIND & (1<<snl_eco)) && ((micros() - centi) <= reverse)) {
      //Serial.print("high");;
    }
    centi = (((uint32_t)micros()) - centi) / (uint32_t)57;        //calculate distance
    //Serial.println(centi);
    
    sum_centi += centi;
    //Serial.print(i+1);
    delay(40);
  }

  sum_centi /= itr;
  //Serial.print("LEFT: ");
  //Serial.println(sum_centi);
  
  return sum_centi;
}

