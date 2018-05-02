//Julius und seine Pflanzen

/////////////////////////////////////////////////
//concerning the numbering of pumps and tanks:
// left = 1 and right = 2 
/////////////////////////////////////////////////



/////////////////////////////////////////////////
//structure for left tank in centimeters and liters
#define left_x 0 
#define left_y 0
#define left_z 0

#define left_sonar_offset 50

/////////////////////////////////////////////////////
//structure for right tank in centimeters and liters
#define right_z1 0     //height to ridge
#define right_z2 0     //overall height

#define right_r1 0     //lowest radius
#define right_r2 0     //midlle radius
#define right_r3 0     //upper radius

#define right_outlet 0     //height of outlet

#define right_sonar_offset 40

//////////////////////////////////

typedef struct pumpl {
  bool active = false;
  uint16_t liters_to_pump = 0;
  uint16_t start_water_height = 0;
  uint16_t end_water_height = 0;
} pumpl;

typedef struct pumpr {
  bool active = false;
  uint16_t liters_to_pump = 0;
  uint16_t start_water_height = 0;
  uint16_t end_water_height = 0;
} pumpr;

pumpl pump_l;
pumpr pump_r;

typedef struct tankl {
  uint16_t max_height = 0;    //cm
  uint16_t min_height = 0;    //cm
  uint16_t ideal_height = 0;    //cm
  
  uint16_t max_volume = 0;    //liters
  uint16_t min_volume = 0;    //liters
  uint16_t ideal_volume = 0;    //liters

  uint16_t act_height = 1;    //cm
  uint16_t act_volume = 20;     //liters
  uint16_t act_percent = 3;   
} tankl;

typedef struct tankr {
  uint16_t max_height = 0;    //cm
  uint16_t min_height = 0;    //cm
  uint16_t ideal_height = 0;    //cm
  
  uint16_t max_volume = 0;    //liters
  uint16_t min_volume = 0;    //liters
  uint16_t ideal_volume = 0;    //liters

  uint16_t act_height = 44;    //cm
  uint16_t act_volume = 45;     //liters
  uint16_t act_percent = 46;   
} tankr;

tankl tank_l; 
tankr tank_r;

uint8_t auto_enabled = true;

uint8_t left_pump_active = false;
uint8_t right_pump_active = false;

uint16_t ideal_liters_tank_left = 300;
uint16_t watering_liters_tank_left = 40;
uint16_t watering_liters_tank_right = 10;
uint16_t watering_liters_when_left_tank_empty = 40;

uint8_t current_minute = 0;
uint8_t current_hour = 0;
uint8_t watering_minute = 0;
uint8_t watering_hour = 8;




#define check_for_negative 0      //check for negative temperature (expermimental)



///////////////////////////////////////////////////////////////
//PINS
#define rtc_sda 4
#define rtc_scl 5

#define bl_tx 10
#define bl_rx 11

#define snr_trg PIND3
#define snr_eco PIND2
#define snl_trg PIND5
#define snl_eco PIND4

#define relai_l 6
#define relai_r 7


//////////////////////////////////////////////////////
////////RTC
#include <DS3232RTC.h>

//////////////////////////////////////////////////////////////////
///Sonar
#define max_dist 150


///////////////////////////////////////////////////////////
//////// BLUETOOTH

#include <SoftwareSerial.h>

SoftwareSerial blSerial(bl_rx, bl_tx); // RX, TX

struct packet {
  bool recent = false;
  uint8_t addr = 0;
  uint8_t data = 0;
} global_packet;



////////////////////////////////////////////////////////////////
////////////////// CODE ///////////////////////////////////////
///////////////////////////////////////////////////////////////
void setup() {
  init1();
}

void loop() {
  if(1) {
    getBluetooth(); 
    if(global_packet.recent) {
      handleCommands();
      global_packet.recent = false;
    }
    
    background();
  } else {
    
  }
  
  delay(10);
}










