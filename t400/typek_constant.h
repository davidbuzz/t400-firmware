#ifndef TYPEK_CONSTANT_H
#define TYPEK_CONSTANT_H

// Macro for accessing thermocouple data
#define lookupThermocouleData(index) (pgm_read_dword(tempTypK + index))

// Note: if switching to eeprom, could look like this instead:
//  #define lookupThermocouleData(index) (eeprom_read_dword(index));

// Lookup Table for the TypK:
// From -270 to 1350°C in steps of 10°C, the list is in µV according to that Temp.
// If changing the lower limit remember to change it in GetTypKTemp().
#define TEMP_TYPE_K_LENGTH 101 // Use the i values indicated below. TEMP_TYPE_K_LENGTH should be i+1

const int32_t tempTypK[TEMP_TYPE_K_LENGTH] PROGMEM = 
{ 
  -6458,  //-270 i=0
  -6411, // -260
  -6404, // -250
  -6344, // -240
  -6262, // -230
  -6158, // -220
  -6035, // -210
  -5891, // -200
  -5730, // -190
  -5550, // -180
  -5354, // -170 i=10
  -5141, // -160
  -4913, // -150
  -4669, // -140
  -4411, // -130
  -4138, // -120
  -3852, // -110
  -3554, // -100
  -3243, // -90
  -2920, // -80
  -2587, // -70 i=20
  -2243, // -60
  -1889, // -50
  -1527, // -40
  -1156,  //-30
  -4778,  //-20
  -392,  //-10
  0,      // 0 // i=27
  397,   // 10
  798,   // 20
  1203,  // 30 i=30
  1612,  // 40
  2023,  // 50
  2436,  // 60
  2851,  // 70
  3267,  // 80
  3682,  // 90
  4096,  // 100
  4509,  // 110
  4920,  // 120
  5328,  // 130 i=40
  5735,  // 140
  6138,  // 150
  6540,  // 160
  6941,  // 170
  7340,  // 180
  7739,  // 190
  8138,  // 200
  8539,  // 210
  8940,  // 220
  9343,  // 230 // i=50
  9747,  // 240
  10153, // 250
  10561, // 260
  10971, // 270
  11382, // 280
  11795, // 290
  12209, // 300
  12624, // 310
  13040, // 320
  13457, // 330 i=60
  13874, // 340
  14293, // 350
  14713, // 360
  15233, // 370
  15554, // 380
  15975, // 390
  16397, // 400
  16820, // 410
  17243, // 420
  17667, // 430 i=70
  18091, // 440
  18516, // 450
  18941, // 460
  19366, // 470
  19792, // 480 // i = 75
  20128, // 490
  20644, // 500
  21071, // 510
  21497, // 520
  21924, // 530 i=80
  22350, // 540
  22776, // 550
  23203, // 560
  23629, // 570
  24055, // 580
  24480, // 590
  24905, // 600
  25330, // 610
  25755, // 620
  26179, // 630 i=90
  26602, // 640
  27025, // 650
  27447, // 660
  27869, // 670
  28289, // 680
  28710, // 690
  29129, // 700
  29548, // 710
  29965, // 720
  30382/*, // 730 i=100 // Numbers past here are beyond the range of int variables.
   30798, // 740        // Do something creative here. Maybe divide these by ten then multiply later.
   31213, // 750        // if (i>25){tempTypeK[i]*10};
   31628, // 760        // Lower resolution from then on, but it may be good enough. Better than nothing.
   32041, // 770
   32453, // 780
   32865, // 790
   33275, // 800
   33685, // 810
   34093, // 820
   34501, // 830 i=110
   34908, // 840
   35313, // 850
   35718, // 860
   36121, // 870
   36524, // 880
   36925, // 890
   37326, // 900
   37725, // 910
   38124, // 920
   38522, // 930 i=120
   38918, // 940
   39314, // 950
   39708, // 960
   40101, // 970
   40494, // 980
   40885, // 990
   41276, // 1000
   41665, // 1010
   42053, // 1020
   42440, // 1030 i=130
   42826, // 1040
   43211, // 1050
   43595, // 1060
   43978, // 1070
   44359, // 1080
   44740, // 1090
   45119, // 1100
   45497, // 1110
   45873, // 1120
   46249, // 1130 i=140
   46623, // 1140
   46995, // 1150
   47367, // 1160
   47737, // 1170
   48105, // 1180
   48473, // 1190
   48838, // 1200
   49202, // 1210
   49565, // 1220
   49926, // 1230 i=150
   50286, // 1240
   50644, // 1250
   51000, // 1260
   51355, // 1270
   51708, // 1280
   52060, // 1290
   52410, // 1300
   52759, // 1310
   53106, // 1320
   53451, // 1330 i=160
   53795, // 1340
   54138, // 1350
   54479, // 1360
   54819, // 1370 i=164
   */
};


#endif
