uint32_t sendDataTimer = millis();

void handleCommands() {
  uint16_t inter = global_packet.data * 10;
  
  switch (global_packet.addr) {
    case 130:
      if(global_packet.data >= 0 && global_packet.data <= 60) {
        current_minute = global_packet.data;
      }
      break;
    case 131:
      if(global_packet.data >= 0 && global_packet.data <= 24) {
        current_hour = global_packet.data;
      }
      break;
    case 132:
      if(global_packet.data >= 0 && global_packet.data <= 60) {
        watering_minute = global_packet.data;
      }
      break;
    case 133:
      if(global_packet.data >= 0 && global_packet.data <= 24) {
        watering_hour = global_packet.data;
      }
      break;
    case 140:
      if(inter >= 0 && inter <= 1000) {
        watering_liters_tank_left = global_packet.data * 10;
      }
      break;
    case 141:
      if(inter >= 0 && inter <= 1000) {
        watering_liters_tank_right = global_packet.data * 10;
      }
      break;
    case 142:
      if(inter >= 0 && inter <= 1000) {
        watering_liters_when_left_tank_empty = global_packet.data * 10;
      }
      break;
    case 143:
      if(inter >= 0 && inter <= 1000) {
        ideal_liters_tank_left = global_packet.data * 10 ;
      }
      break;
    case 150:
      if(global_packet.data == 1) {
        left_pump_active = 1;
      } else if(global_packet.data == 0) {
        left_pump_active = 0;
      }
      break;
    case 151:
      if(global_packet.data == 1) {
        right_pump_active = 1;
      } else if(global_packet.data == 0) {
        right_pump_active = 0;
      }
      break;
    case 153:
      if(global_packet.data == 1) {
        auto_enabled = 1;
      } else if(global_packet.data == 0) {
        auto_enabled = 0;
      }
      break;
    default: 
      
      break;
  } 
}


void background() {
  checkWaterHeight();
  setSysTime();
  checkTime();
  
  if(millis() - sendDataTimer >= 10000) {
     sendData();
     sendDataTimer = millis();
  }
  
}

void checkWaterHeight() {
  
}

void checkTime() {
  if(checkTime(watering_hour, watering_minute)) {
    
  }
}




