// -------------------------------------------- CUSTOM PATTERNS LIST ---------------------------------------------
// These array of indexes are used by customPattern() function in LEDMask
// They correspond to the layout and NUM_OF_LEDS in the setup

uint_least8_t bigVPattern[NUM_LEDS] = {
  // BIG V
0,  1,  2,  3,  4,  5,  6,  7,  6,  5,  4,  3,  2,  1,  0, 
  0,  1,  2,  3,  4,  5,  6,  6,  5,  4,  3,  2,  1,  0,  
    0,  1,  2,  3,  4,  5,  6,  5,  4,  3,  2,  1,  0,  
      0,  1,  2,  3,  4,  5,  5,  4,  3,  2,  1,  0,    
        0,  1,  2,  3,  4,  5,  4,  3,  2,  1,  0,    
          0,  1,  2,  3,  4,  4,  3,  2,  1,  0,            
};

uint_least8_t trianglesPattern[NUM_LEDS] = {
  // TRIANGLES
9,  8,  7,  6,  5,  4,  3,  2,  3,  4,  5,  6,  7,  8,  9, 
  8,  7,  6,  5,  4,  3,  2,  2,  3,  4,  5,  6,  7,  8,  
    7,  6,  5,  4,  3,  2,  1,  2,  3,  4,  5,  6,  7,  
      6,  5,  4,  3,  2,  1,  1,  2,  3,  4,  5,  6,    
        5,  4,  3,  2,  1,  0,  1,  2,  3,  4,  5,    
          4,  3,  2,  1,  0,  0,  1,  2,  3,  4,      
};

uint_least8_t circlesPattern[NUM_LEDS] = {
  // CIRCLES
1,  0,  6,  5,  4,  3,  2,  2,  2,  3,  4,  5,  6,  0,  1, 
  0,  6,  5,  4,  3,  2,  1,  1,  2,  3,  4,  5,  6,  0,  
    6,  5,  4,  3,  2,  1,  0,  1,  2,  3,  4,  5,  6,  
      5,  4,  3,  2,  2,  1,  1,  2,  3,  3,  4,  5,    
        5,  4,  3,  2,  2,  2,  2,  3,  3,  4,  5,    
           5,  4,  3,  2,  1,  1,  2,  3,  4,  5,         
};

uint_least8_t outwardsWingsPattern[NUM_LEDS] = {
  // OUTWARDS WINGS
0,  2,  4,  6,  8,  10,   12,   14,   12,   10,   8,  6,  4,  2,  0, 
  2,  4,  6,  8,  10,   12,   14,   14,   12,   10,   8,  6,  4,  2,  
    4,  6,  8,  10,   12,   14,   0,  14,   12,   10,   8,  6,  4,  
      4,  6,  8,  10,   12,   14,   14,   12,   10,   8,  6,  4,    
        4,  6,  8,  10,   12,   14,   12,   10,   8,  6,  4,    
          4,  6,  8,  10,   12,   12,   10,   8,  6,  4,       
};

uint_least8_t scrollingRowPattern[NUM_LEDS] = {
  // SCROLLING ROW
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  
    4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  
      6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,    
        8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,    
          10, 10, 10, 10, 10, 10, 10, 10, 10, 10,          
};

uint_least8_t scrollingColumnPattern[NUM_LEDS] = {
  // SCROLLING COLUMN
0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,   11,   12,   13,   14, 
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,   11,   12,   13,   
    1,  2,  3,  4,  5,  6,  7,  8,  9,  10,   11,   12,   13,   
      1,  2,  3,  4,  5,  6,  7,  8,  9,  10,   11,   12,     
        2,  3,  4,  5,  6,  7,  8,  9,  10,   11,   12,     
          2,  3,  4,  5,  6,  7,  8,  9,  10,   11,  
};

uint_least8_t crossLinesPattern[NUM_LEDS] = {
  // CROSSING COLUMN
0,   1,  2,  3,  4,  5,  6,  7,  8,  9,  10,   11,   12,   13,   14, 
 13,   12,   11,   10,   9,  8,  7,  6,  5,  4,  3,  2,  1,  0,  
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,   11,   12,   
     11,   10,   9,  8,  7,  6,  5,  4,  3,  2,  1,  0,    
       0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,     
          9,  8,  7,  6,  5,  4,  3,  2,  1,  0,       
};

// Color Bridge

uint_least8_t scrollingColors[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

// ------------------------------------------- END CUSTOM PATTERNS LIST --------------------------------------------

// --------------------------------------------- CUSTOM PALETTES LIST ---------------------------------------------

DEFINE_GRADIENT_PALETTE( ib_jul01_gp ) {
    0, 194,  1,  1,
   94,   1, 29, 18,
  132,  57,131, 28,
  255, 113,  1,  1};

DEFINE_GRADIENT_PALETTE( es_vintage_01_gp ) {
    0,   4,  1,  1,
   51,  16,  0,  1,
   76,  97,104,  3,
  101, 255,131, 19,
  127,  67,  9,  4,
  153,  16,  0,  1,
  229,   4,  1,  1,
  255,   4,  1,  1};

DEFINE_GRADIENT_PALETTE( rgi_15_gp ) {
    0,   4,  1, 31,
   31,  55,  1, 16,
   63, 197,  3,  7,
   95,  59,  2, 17,
  127,   6,  2, 34,
  159,  39,  6, 33,
  191, 112, 13, 32,
  223,  56,  9, 35,
  255,  22,  6, 38};

DEFINE_GRADIENT_PALETTE( retro2_16_gp ) {
    0, 188,135,  1,
  255,  46,  7,  1};

DEFINE_GRADIENT_PALETTE( Analogous_1_gp ) {
    0,   3,  0,255,
   63,  23,  0,255,
  127,  67,  0,255,
  191, 142,  0, 45,
  255, 255,  0,  0};

DEFINE_GRADIENT_PALETTE( Coral_reef_gp ) {
    0,  40,199,197,
   50,  10,152,155,
   96,   1,111,120,
   96,  43,127,162,
  139,  10, 73,111,
  255,   1, 34, 71};

DEFINE_GRADIENT_PALETTE( es_ocean_breeze_068_gp ) {
    0, 100,156,153,
   51,   1, 99,137,
  101,   1, 68, 84,
  104,  35,142,168,
  178,   0, 63,117,
  255,   1, 10, 10};

DEFINE_GRADIENT_PALETTE( es_ocean_breeze_036_gp ) {
    0,   1,  6,  7,
   89,   1, 99,111,
  153, 144,209,255,
  255,   0, 73, 82};

DEFINE_GRADIENT_PALETTE( es_landscape_33_gp ) {
    0,   1,  5,  0,
   19,  32, 23,  1,
   38, 161, 55,  1,
   63, 229,144,  1,
   66,  39,142, 74,
  255,   1,  4,  1};

DEFINE_GRADIENT_PALETTE( gr65_hult_gp ) {
    0, 247,176,247,
   48, 255,136,255,
   89, 220, 29,226,
  160,   7, 82,178,
  216,   1,124,109,
  255,   1,124,109};

DEFINE_GRADIENT_PALETTE( GMT_drywet_gp ) {
    0,  47, 30,  2,
   42, 213,147, 24,
   84, 103,219, 52,
  127,   3,219,207,
  170,   1, 48,214,
  212,   1,  1,111,
  255,   1,  7, 33};

DEFINE_GRADIENT_PALETTE( es_emerald_dragon_08_gp ) {
    0,  97,255,  1,
  101,  47,133,  1,
  178,  13, 43,  1,
  255,   2, 10,  1};

DEFINE_GRADIENT_PALETTE( lava_gp ) {
    0,   0,  0,  0,
   46,  18,  0,  0,
   96, 113,  0,  0,
  108, 142,  3,  1,
  119, 175, 17,  1,
  146, 213, 44,  2,
  174, 255, 82,  4,
  188, 255,115,  4,
  202, 255,156,  4,
  218, 255,203,  4,
  234, 255,255,  4,
  244, 255,255, 71,
  255, 255,255,255};

DEFINE_GRADIENT_PALETTE( fire_gp ) {
    0,   1,  1,  0,
   76,  32,  5,  0,
  146, 192, 24,  0,
  197, 220,105,  5,
  240, 252,255, 31,
  250, 252,255,111,
  255, 255,255,255};

DEFINE_GRADIENT_PALETTE( Pink_Purple_gp ) {
    0,  19,  2, 39,
   25,  26,  4, 45,
   51,  33,  6, 52,
   76,  68, 62,125,
  102, 118,187,240,
  109, 163,215,247,
  114, 217,244,255,
  122, 159,149,221,
  149, 113, 78,188,
  183, 128, 57,155,
  255, 146, 40,123};

DEFINE_GRADIENT_PALETTE( Sunset_Real_gp ) {
    0, 120,  0,  0,
   22, 179, 22,  0,
   51, 255,104,  0,
   85, 167, 22, 18,
  135, 100,  0,103,
  198,  16,  0,130,
  255,   0,  0,160};

DEFINE_GRADIENT_PALETTE( BlacK_Blue_Magenta_White_gp ) {
    0,   0,  0,  0,
   42,   0,  0, 45,
   84,   0,  0,255,
  127,  42,  0,255,
  170, 255,  0,255,
  212, 255, 55,255,
  255, 255,255,255};

DEFINE_GRADIENT_PALETTE( BlacK_Red_Magenta_Yellow_gp ) {
    0,   0,  0,  0,
   42,  42,  0,  0,
   84, 255,  0,  0,
  127, 255,  0, 45,
  170, 255,  0,255,
  212, 255, 55, 45,
  255, 255,255,  0};

DEFINE_GRADIENT_PALETTE( Blue_Cyan_Yellow_gp ) {
    0,   0,  0,255,
   63,   0, 55,255,
  127,   0,255,255,
  191,  42,255, 45,
  255, 255,255,  0};

DEFINE_GRADIENT_PALETTE( temperature_gp ) {
    0,   1, 27,105,
   14,   1, 27,105,
   15,   1, 40,127,
   28,   1, 40,127,
   29,   1, 70,168,
   42,   1, 70,168,
   43,   1, 92,197,
   56,   1, 92,197,
   57,   1,119,221,
   70,   1,119,221,
   71,   3,130,151,
   84,   3,130,151,
   85,  23,156,149,
   99,  23,156,149,
  100,  67,182,112,
  113,  67,182,112,
  114, 121,201, 52,
  127, 121,201, 52,
  128, 142,203, 11,
  141, 142,203, 11,
  142, 224,223,  1,
  155, 224,223,  1,
  156, 252,187,  2,
  170, 252,187,  2,
  171, 247,147,  1,
  184, 247,147,  1,
  185, 237, 87,  1,
  198, 237, 87,  1,
  199, 229, 43,  1,
  212, 229, 43,  1,
  213, 220, 15,  1,
  226, 220, 15,  1,
  227, 171,  2,  2,
  240, 171,  2,  2,
  241,  80,  3,  3,
  255,  80,  3,  3};

DEFINE_GRADIENT_PALETTE( bhw1_03_gp ) {
    0,   0,  0,  0,
  137,  11,112,153,
  191,  40,219,105,
  255, 255,255,255};

DEFINE_GRADIENT_PALETTE( bhw1_04_gp ) {
    0, 229,227,  1,
   15, 227,101,  3,
  142,  40,  1, 80,
  198,  17,  1, 79,
  255,   0,  0, 45};

DEFINE_GRADIENT_PALETTE( bhw1_05_gp ) {
    0,   1,221, 53,
  255,  73,  3,178};

DEFINE_GRADIENT_PALETTE( bhw1_06_gp ) {
    0, 184,  1,128,
  160,   1,193,182,
  219, 153,227,190,
  255, 255,255,255};

DEFINE_GRADIENT_PALETTE( bhw1_11_gp ) {
    0,  12, 21, 29,
   35,  19,  1,  2,
  127, 249,193,210,
  224,  19,  1,  2,
  255,  12, 21, 29};

DEFINE_GRADIENT_PALETTE( bhw1_13_gp ) {
    0, 255,255, 45,
  255, 157, 57,197};

DEFINE_GRADIENT_PALETTE( bhw1_14_gp ) {
    0,   0,  0,  0,
   12,   1,  1,  3,
   53,   8,  1, 22,
   80,   4,  6, 89,
  119,   2, 25,216,
  145,   7, 10, 99,
  186,  15,  2, 31,
  233,   2,  1,  5,
  255,   0,  0,  0};

DEFINE_GRADIENT_PALETTE( bhw1_15_gp ) {
    0,   1,  8, 87,
   71,  23,195,130,
  122, 186,248,233,
  168,  23,195,130,
  255,   1,  8, 87};

DEFINE_GRADIENT_PALETTE( bhw1_18_gp ) {
    0,   0,  0,  0,
    9,  16, 10,  7,
   53, 101, 51, 41,
   89, 194, 58, 29,
  104, 220,118, 87,
  122, 244,199,182,
  153, 194, 58, 29,
  193, 101, 51, 41,
  242,  16, 10,  7,
  255,   0,  0,  0};

DEFINE_GRADIENT_PALETTE( bhw1_22_gp ) {
    0,   1,  1,  1,
   45,  30, 10,  1,
   96,  60,  9,  1,
  130, 197, 36, 12,
  188,  30, 10,  1,
  255,   1,  1,  1};

DEFINE_GRADIENT_PALETTE( bhw1_27_gp ) {
    0,  16,  2, 50,
   61,  87, 31,180,
  114, 255,255,255,
  196,  87, 31,180,
  255, 220, 27,112};

DEFINE_GRADIENT_PALETTE( bhw1_28_gp ) {
    0,  75,  1,221,
   30, 252, 73,255,
   48, 169,  0,242,
  119,   0,149,242,
  170,  43,  0,242,
  206, 252, 73,255,
  232,  78, 12,214,
  255,   0,149,242};

DEFINE_GRADIENT_PALETTE( bhw1_32_gp ) {
    0,   0,  0,  0,
   32,   7, 12,  8,
   71,  42, 55, 45,
  108,  39,119, 73,
  130,  36,209,109,
  149,  39,119, 73,
  186,  42, 55, 45,
  230,   7, 12,  8,
  255,   0,  0,  0};

DEFINE_GRADIENT_PALETTE( bhw1_greeny_gp ) {
    0,   0,  0,  0,
   39,   7, 55,  8,
   99,  42,255, 45,
  153,   7, 55,  8,
  255,   0,  0,  0};

DEFINE_GRADIENT_PALETTE( bhw1_harvest_gp ) {
    0,   9,  5,  1,
   89, 206, 41,  4,
  132, 192, 84, 23,
  182,  65, 31,  7,
  255,   9,  5,  1};

DEFINE_GRADIENT_PALETTE( bhw1_purpgreen_gp ) {
    0,  21,  1, 35,
   27,  35, 16, 51,
   73,  54, 55, 68,
  101,  84,136, 95,
  119, 121,255,125,
  167,  59, 66, 72,
  255,  21,  1, 35};

DEFINE_GRADIENT_PALETTE( bhw1_purplered_gp ) {
    0, 255,  0,  0,
  255, 107,  1,205};

DEFINE_GRADIENT_PALETTE( bhw1_sunconure_gp ) {
    0,  20,223, 13,
  160, 232, 65,  1,
  252, 232,  5,  1,
  255, 232,  5,  1};

DEFINE_GRADIENT_PALETTE( bhw1_sunset1_gp ) {
    0,  33, 21, 25,
   38, 125, 29, 20,
   71, 222, 59, 30,
  145, 190,147,127,
  178,  88,136,203,
  255,   3, 24, 78};

DEFINE_GRADIENT_PALETTE( bhw1_sunset2_gp ) {
    0, 255,175,  8,
   81, 237, 29, 10,
  137, 148, 57, 42,
  165,  68, 54, 54,
  255,  18, 23, 29};

DEFINE_GRADIENT_PALETTE( bhw1_three_gp ) {
    0, 255,255,255,
   45,   7, 12,255,
  112, 227,  1,127,
  112, 227,  1,127,
  140, 255,255,255,
  155, 227,  1,127,
  196,  45,  1, 99,
  255, 255,255,255};

DEFINE_GRADIENT_PALETTE( bhw1_w00t_gp ) {
    0,   3, 13, 43,
  104,  78,141,240,
  188, 255,  0,  0,
  255,  28,  1,  1};

// --------------------------------------------- END CUSTOM PALETTES LIST ---------------------------------------------

  
// ------------------- PALETTE GROUPS ------------------------------  

// -------------------- Full Library -------------------------------  

//const TProgmemRGBGradientPalettePtr gGradientPalettes[] = {
//Sunset_Real_gp,
//es_ocean_breeze_036_gp,
//rgi_15_gp,
//retro2_16_gp,
//Analogous_1_gp,
//Coral_reef_gp,
//es_ocean_breeze_068_gp,
//es_vintage_01_gp,
//es_landscape_33_gp,
//gr65_hult_gp,
//GMT_drywet_gp,
//ib_jul01_gp,
//es_emerald_dragon_08_gp,
//lava_gp,
//fire_gp,
//Pink_Purple_gp,
//BlacK_Blue_Magenta_White_gp,
//BlacK_Red_Magenta_Yellow_gp,
//Blue_Cyan_Yellow_gp,
//temperature_gp,
//bhw1_03_gp,
//bhw1_04_gp,
//bhw1_05_gp,
//bhw1_06_gp,
//bhw1_11_gp,
//bhw1_13_gp,
//bhw1_14_gp,
//bhw1_15_gp,
//bhw1_18_gp,
//bhw1_22_gp,
//bhw1_27_gp,
//bhw1_28_gp,
//bhw1_32_gp,
//bhw1_greeny_gp,
//bhw1_harvest_gp,
//bhw1_purpgreen_gp,
//bhw1_purplered_gp,
//bhw1_sunconure_gp,
//bhw1_sunset1_gp,
//bhw1_sunset2_gp,
//bhw1_three_gp,
//bhw1_w00t_gp,
//    };
//
// Count of how many cpt-city gradients are defined in the full library:
//  uint8_t gGradientPalettesCount =   sizeof( gGradientPalettes) / sizeof( TProgmemRGBGradientPalettePtr );

// -------------------- Custom Circles -------------------------------  

const TProgmemRGBGradientPalettePtr gCirclesPalettes[] = {
Sunset_Real_gp,
es_ocean_breeze_036_gp,
Analogous_1_gp,
es_vintage_01_gp,
es_landscape_33_gp,
GMT_drywet_gp,
ib_jul01_gp,
fire_gp,
Pink_Purple_gp,
BlacK_Blue_Magenta_White_gp,
Blue_Cyan_Yellow_gp,
temperature_gp,
bhw1_03_gp,
bhw1_04_gp,
bhw1_05_gp,
bhw1_06_gp,
bhw1_11_gp,
bhw1_14_gp,
bhw1_15_gp,
bhw1_18_gp,
bhw1_22_gp,
bhw1_27_gp,
bhw1_32_gp,
bhw1_greeny_gp,
bhw1_harvest_gp,
bhw1_purpgreen_gp,
bhw1_sunconure_gp,
bhw1_sunset1_gp,
bhw1_w00t_gp,
    };

// Count of how many palettes in this array
 uint8_t gCirclesPalettesCount =   sizeof( gCirclesPalettes) / sizeof( TProgmemRGBGradientPalettePtr );

// -------------------- Custom Triangles -------------------------------  

const TProgmemRGBGradientPalettePtr gTrianglesPalettes[] = {
Sunset_Real_gp,
rgi_15_gp,
Analogous_1_gp,
es_vintage_01_gp,
es_landscape_33_gp,
gr65_hult_gp,
GMT_drywet_gp,
ib_jul01_gp,
es_emerald_dragon_08_gp,
lava_gp,
fire_gp,
BlacK_Blue_Magenta_White_gp,
BlacK_Red_Magenta_Yellow_gp,
Blue_Cyan_Yellow_gp,
temperature_gp,
bhw1_03_gp,
bhw1_04_gp,
bhw1_05_gp,
bhw1_06_gp,
bhw1_11_gp,
bhw1_13_gp,
bhw1_14_gp,
bhw1_15_gp,
bhw1_18_gp,
bhw1_22_gp,
bhw1_27_gp,
bhw1_28_gp,
bhw1_32_gp,
bhw1_greeny_gp,
bhw1_harvest_gp,
bhw1_purpgreen_gp,
bhw1_purplered_gp,
bhw1_sunconure_gp,
bhw1_sunset1_gp,
bhw1_sunset2_gp,
bhw1_three_gp,
bhw1_w00t_gp,
    };

// Count of how many palettes in this array
 uint8_t gTrianglesPalettesCount =   sizeof( gTrianglesPalettes) / sizeof( TProgmemRGBGradientPalettePtr );

// -------------------- Custom Outwards Wings -------------------------------  

const TProgmemRGBGradientPalettePtr gOutwardsWingsPalettes[] = {
Sunset_Real_gp,
rgi_15_gp,
Analogous_1_gp,
Coral_reef_gp,
es_vintage_01_gp,
es_landscape_33_gp,
GMT_drywet_gp,
ib_jul01_gp,
lava_gp,
fire_gp,
Pink_Purple_gp,
BlacK_Blue_Magenta_White_gp,
BlacK_Red_Magenta_Yellow_gp,
Blue_Cyan_Yellow_gp,
temperature_gp,
bhw1_03_gp,
bhw1_04_gp,
bhw1_05_gp,
bhw1_06_gp,
bhw1_11_gp,
bhw1_13_gp,
bhw1_14_gp,
bhw1_15_gp,
bhw1_18_gp,
bhw1_22_gp,
bhw1_27_gp,
bhw1_28_gp,
bhw1_purpgreen_gp,
bhw1_purplered_gp,
bhw1_sunconure_gp,
bhw1_sunset1_gp,
bhw1_three_gp,
    };

// Count of how many palettes in this array
 uint8_t gOutwardsWingsPalettesCount =   sizeof( gOutwardsWingsPalettes) / sizeof( TProgmemRGBGradientPalettePtr );

// -------------------- Custom Big V -------------------------------  

const TProgmemRGBGradientPalettePtr gBigVPalettes[] = {
Sunset_Real_gp,
es_ocean_breeze_036_gp,
rgi_15_gp,
retro2_16_gp,
Analogous_1_gp,
es_ocean_breeze_068_gp,
es_vintage_01_gp,
es_landscape_33_gp,
GMT_drywet_gp,
ib_jul01_gp,
lava_gp,
Blue_Cyan_Yellow_gp,
temperature_gp,
bhw1_03_gp,
bhw1_04_gp,
bhw1_05_gp,
bhw1_06_gp,
bhw1_11_gp,
bhw1_13_gp,
bhw1_14_gp,
bhw1_15_gp,
bhw1_18_gp,
bhw1_22_gp,
bhw1_27_gp,
bhw1_28_gp,
bhw1_32_gp,
bhw1_greeny_gp,
bhw1_harvest_gp,
bhw1_purpgreen_gp,
bhw1_purplered_gp,
bhw1_sunconure_gp,
bhw1_sunset1_gp,
bhw1_sunset2_gp,
bhw1_three_gp,
bhw1_w00t_gp,
    };

// Count of how many palettes in this array
 uint8_t gBigVPalettesCount =   sizeof( gBigVPalettes) / sizeof( TProgmemRGBGradientPalettePtr );

// -------------------- Custom Scrolling Row -------------------------------  

const TProgmemRGBGradientPalettePtr gScrollingRowPalettes[] = {
Sunset_Real_gp,
es_ocean_breeze_036_gp,
retro2_16_gp,
Analogous_1_gp,
Coral_reef_gp,
es_vintage_01_gp,
es_landscape_33_gp,
gr65_hult_gp,
GMT_drywet_gp,
ib_jul01_gp,
lava_gp,
fire_gp,
Pink_Purple_gp,
BlacK_Red_Magenta_Yellow_gp,
Blue_Cyan_Yellow_gp,
temperature_gp,
bhw1_03_gp,
bhw1_04_gp,
bhw1_05_gp,
bhw1_06_gp,
bhw1_15_gp,
bhw1_22_gp,
bhw1_27_gp,
bhw1_28_gp,
bhw1_purplered_gp,
bhw1_sunconure_gp,
bhw1_sunset1_gp,
bhw1_three_gp,
bhw1_w00t_gp,
    };

// Count of how many palettes in this array
 uint8_t gScrollingRowPalettesCount =   sizeof( gScrollingRowPalettes) / sizeof( TProgmemRGBGradientPalettePtr );

// -------------------- Custom Scrolling Column -------------------------------  

const TProgmemRGBGradientPalettePtr gScrollingColumnPalettes[] = {
Sunset_Real_gp,
es_ocean_breeze_036_gp,
rgi_15_gp,
retro2_16_gp,
Analogous_1_gp,
es_ocean_breeze_068_gp,
es_vintage_01_gp,
es_landscape_33_gp,
gr65_hult_gp,
GMT_drywet_gp,
ib_jul01_gp,
es_emerald_dragon_08_gp,
lava_gp,
fire_gp,
Pink_Purple_gp,
BlacK_Blue_Magenta_White_gp,
BlacK_Red_Magenta_Yellow_gp,
Blue_Cyan_Yellow_gp,
temperature_gp,
bhw1_03_gp,
bhw1_04_gp,
bhw1_05_gp,
bhw1_06_gp,
bhw1_13_gp,
bhw1_15_gp,
bhw1_greeny_gp,
bhw1_harvest_gp,
bhw1_purpgreen_gp,
bhw1_purplered_gp,
bhw1_sunconure_gp,
bhw1_sunset1_gp,
bhw1_w00t_gp,
    };

// Count of how many palettes in this array
 uint8_t gScrollingColumnPalettesCount =   sizeof( gScrollingColumnPalettes) / sizeof( TProgmemRGBGradientPalettePtr );

// -------------------- Custom Crossing Lines -------------------------------  

const TProgmemRGBGradientPalettePtr gCrossLinesPalettes[] = {
Sunset_Real_gp,
es_ocean_breeze_036_gp,
rgi_15_gp,
retro2_16_gp,
Analogous_1_gp,
Coral_reef_gp,
es_ocean_breeze_068_gp,
es_vintage_01_gp,
es_landscape_33_gp,
gr65_hult_gp,
GMT_drywet_gp,
ib_jul01_gp,
es_emerald_dragon_08_gp,
lava_gp,
fire_gp,
Pink_Purple_gp,
BlacK_Blue_Magenta_White_gp,
BlacK_Red_Magenta_Yellow_gp,
Blue_Cyan_Yellow_gp,
temperature_gp,
bhw1_03_gp,
bhw1_04_gp,
bhw1_05_gp,
bhw1_06_gp,
bhw1_11_gp,
bhw1_13_gp,
bhw1_14_gp,
bhw1_15_gp,
bhw1_18_gp,
bhw1_22_gp,
bhw1_27_gp,
bhw1_28_gp,
bhw1_32_gp,
bhw1_greeny_gp,
bhw1_harvest_gp,
bhw1_purpgreen_gp,
bhw1_purplered_gp,
bhw1_sunconure_gp,
bhw1_sunset1_gp,
bhw1_sunset2_gp,
bhw1_three_gp,
bhw1_w00t_gp,
    };

// Count of how many palettes in this array
 uint8_t gCrossLinesPalettesCount =   sizeof( gCrossLinesPalettes) / sizeof( TProgmemRGBGradientPalettePtr );
 
 
