





uint16_t leftVolToCenti(uint16_t vol) {
  return vol / 2;
}

uint16_t rightVolToCenti(uint16_t vol) {
  return vol / 2;
}

uint16_t leftCentiToVol(uint16_t centi) {
  return centi * 2;
}

uint16_t rightCentiToVol(uint16_t centi) {
  return centi * 2;
}

uint8_t leftPercent() {
  return (uint8_t) ((tank_l.act_volume / (tank_l.max_volume - tank_l.min_volume)) * 100);
}

uint8_t rightPercent() {
  return (uint8_t) ((tank_r.act_volume / (tank_r.max_volume - tank_r.min_volume)) * 100);
}

void pumpLeft(bool power) { 
  if(power && (!check_for_negative || true)) {
    digitalWrite(relai_l, HIGH);
  } else if(!power) {
    digitalWrite(relai_l, LOW);
  }
}

void pumpRight(bool power) { 
  if(power && (!check_for_negative || true)) {
    digitalWrite(relai_r, HIGH);
  } else if(!power) {
    digitalWrite(relai_r, LOW);
  }
}
