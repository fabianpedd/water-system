/* Bluetooth command mapping
 * Adresses:
 * 
 * /////////incomming/////////////
 * 100-109 reserved
 *  
 * 130 set_current_minute
 * 131 set_current_hour
 * 132 set_watering_minute
 * 133 set_watering_hour
 * 
 * 140 water_liters_tank_left
 * 141 water_liters_tank_right
 * 142 water_liters_tank_when_left_tank_empty
 * 143 ideal_liter_left
 * 
 * 150 activate_left_pump
 * 151 activate_right_pump
 * 
 * 153 enable_auto
 * 
 * 
 * /////////outgoing//////////////
 * 200-209 reserved
 * 
 * 210 live_cm_left
 * 211 live_liter_left
 * 212 live_precent_left
 *
 * 220 live_cm_right
 * 221 live_liter_right
 * 222 live_percent_right
 * 
 * 230 current_minute
 * 231 current_hour
 * 232 watering_minute
 * 233 watering_hour
 * 
 * 240 water_liters_tank_left
 * 241 water_liters_tank_right
 * 242 water_liters_tank_when_left_tank_empty
 * 243 ideal_liter_left
 * 
 * 250 left_pump_active
 * 251 right_pump_active
 * 
 * 253 auto_enabled
 */

void sendData() {
  sendBluetooth(210, (uint8_t) tank_l.act_height);
  sendBluetooth(211, (uint8_t) (tank_l.act_volume / 10));
  sendBluetooth(212, (uint8_t) tank_l.act_percent);

  sendBluetooth(220, (uint8_t) tank_r.act_height);
  sendBluetooth(221, (uint8_t) (tank_r.act_volume / 10));
  sendBluetooth(222, (uint8_t) tank_r.act_percent);

  sendBluetooth(230, current_minute);
  sendBluetooth(231, current_hour);
  sendBluetooth(232, watering_minute);
  sendBluetooth(233, watering_hour);

  sendBluetooth(240, (uint8_t) (watering_liters_tank_left / 10));
  sendBluetooth(241, (uint8_t) (watering_liters_tank_right / 10));
  sendBluetooth(242, (uint8_t) (watering_liters_when_left_tank_empty / 10));
  sendBluetooth(243, (uint8_t) (ideal_liters_tank_left / 10));

  sendBluetooth(250, left_pump_active);
  sendBluetooth(251, right_pump_active);
  sendBluetooth(253, auto_enabled);
  
}


void testSerial() {
  if (blSerial.available()) {
    Serial.write(blSerial.read());
  }
  if (Serial.available()) {
    blSerial.write(Serial.read());
  }
}

void getBluetooth() {
  if (blSerial.available() >= 3) {
    uint8_t token = (uint8_t) blSerial.read();
    uint8_t add = 0;
    uint8_t dat = 0;
    if (254 == token) {
      add = (uint8_t) blSerial.read();
      if(add == 130 || add == 131
      || add == 132 || add == 133
      || add == 140 || add == 141
      || add == 142 || add == 143 
      || add == 150 || add == 151
      || add == 153 || add == 153) {
        dat = (uint8_t) blSerial.read();
        if(dat != 254) {
          global_packet.recent = true;
          global_packet.addr = add;
          global_packet.data = dat;
        }
      }
    }
    Serial.print("Token: ");
    Serial.print(token);
    if(global_packet.recent) {
      Serial.print(" Ad: ");
      Serial.print(add);
      Serial.print(" Data: ");
      Serial.println(dat);
    } else Serial.println(""); 
  }
}

void sendBluetooth(uint8_t add, uint8_t dat) {
  
  blSerial.write(254);
  blSerial.write(add);
  if(dat == 254) {
    dat = 255;
  }
  blSerial.write(dat);
  Serial.print("Data Send: ");
  Serial.print(add);
  Serial.print(" ");
  Serial.println(dat);
  delay(20);
}



