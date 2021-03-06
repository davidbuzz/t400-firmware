#include "Arduino.h"  // for boolean type


#include "t400.h"
#include "sd_log.h"


#ifdef SDCARD
#include <SdFat.h>
#endif


extern uint8_t temperatureUnit;

namespace sd {

#ifdef SDCARD
SdFat sd;
SdFile file;
#endif

uint32_t syncTime      = 0;     // time of last sync(), in millis()

//void error_P(const char* str) {
//  Serial.print("error: ");
//  Serial.print(str);
//  
//  // Stop the SD card
//  close();
//}

void init() {
  close();
  #ifdef SDCARD
  if (!sd.begin(SD_CS, SPI_FULL_SPEED)) {
//    error_P("card.init");
    return;
  }
  #endif
}

bool open(char* fileName) {
  // Create LDxxxx.CSV for the lowest value of x.

  #ifdef SDCARD
  uint16_t i = 0;
  do {
    fileName[2] = (i/1000) % 10 + '0';
    fileName[3] = (i/100)  % 10 + '0';
    fileName[4] = (i/10)   % 10 + '0';
    fileName[5] = i        % 10 + '0';
    i++;
  }
  while(sd.exists(fileName));


  if(!file.open(fileName, O_CREAT | O_WRITE | O_EXCL)) {
//    error_P("file open");
    return false;
  }
  file.clearWriteError();
  
  // write data header
  file.print("time (s)");

  #endif
  
  Serial.print("v");
  Serial.println(FIRMWARE_VERSION);

  Serial.print("File: ");
  Serial.println(fileName);

  // write data header
  Serial.print("time (s)");
  
  /* We are no longer using the junction temperature in our data output.
  // write data header
  file.print("time (s), ambient");
  Serial.print("time (s), ambient");
  
  switch(temperatureUnit) {
  case TEMPERATURE_UNITS_C:
    file.print(" (C)");
    Serial.print(" (C)");
    break;
  case TEMPERATURE_UNITS_F:
    file.print(" (F)");
    Serial.print(" (F)");
    break;
  case TEMPERATURE_UNITS_K:
    file.print(" (K)");
    Serial.print(" (K)");
    break;
    
  }*/

  for (uint8_t i = 0; i < SENSOR_COUNT; i++) {
    #ifdef SDCARD
    file.print(", temp_");
    file.print(i, DEC);
    #endif
    
    Serial.print(", temp_");
    Serial.print(i, DEC);
    
    switch(temperatureUnit) {
    case TEMPERATURE_UNITS_C:
      #ifdef SDCARD
      file.print(" (C)");
      #endif
      Serial.print(" (C)");
      break;
    case TEMPERATURE_UNITS_F:
      #ifdef SDCARD
      file.print(" (F)");
      #endif
      Serial.print(" (F)");
      break;
    case TEMPERATURE_UNITS_K:
      #ifdef SDCARD
      file.print(" (K)");
      #endif
      Serial.print(" (K)");
      break;
    }
  }
  #ifdef SDCARD
  file.println();
  file.flush();
  #endif
  Serial.println();

  #ifdef SDCARD
  return (file.getWriteError() == false);
  #else
    return true;
  #endif
}

void close() {
  #ifdef SDCARD
  file.close();
  #endif
}

bool log(char* message) {
  // TODO: Test if file is open first
  
  // log time to file
  #ifdef SDCARD
  file.println(message);
  #endif

  sync(false);

  #ifdef SDCARD
  return (file.getWriteError() == false);
  #else
    return true;
  #endif
}

void sync(boolean force) {
  // TODO: Test if file is open first?
  
  //don't sync too often - requires 2048 bytes of I/O to SD card
  
  if (!force && (millis() - syncTime) <  SYNC_INTERVAL) {
    return;
  }
  
  syncTime = millis();
  #ifdef SDCARD
  file.flush();
  #endif
}

} // namespace sd
