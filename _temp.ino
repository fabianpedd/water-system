int8_t getTemp() {
  int8_t temp1, temp2;
  temp1 = (int8_t) getTempExt();
  temp2 = (int8_t) getTempInt();

  if(abs(temp1 - temp2) >= 2) {
    return -100;
  } else {
    return (int8_t) (temp1 + temp2) / 2;
  }
}

double getTempExt() {
  return RTC.temperature() / 4.0;
}

double getTempInt(void)
{
  unsigned int wADC;
  double t;

  // The internal temperature has to be used
  // with the internal reference of 1.1V.
  // Channel 8 can not be selected with
  // the analogRead function yet.

  // Set the internal reference and mux.
  ADMUX = (_BV(REFS1) | _BV(REFS0) | _BV(MUX3));
  ADCSRA |= _BV(ADEN);  // enable the ADC

  delay(20);            // wait for voltages to become stable.

  ADCSRA |= _BV(ADSC);  // Start the ADC

  // Detect end-of-conversion
  while (bit_is_set(ADCSRA,ADSC));

  // Reading register "ADCW" takes care of how to read ADCL and ADCH.
  wADC = ADCW;

  // The offset of 324.31 could be wrong. It is just an indication.
  t = (wADC - 324.31 ) / 1.22;

  // The returned temperature is in degrees Celsius.
  return (t);
}
