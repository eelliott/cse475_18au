#include "Neopixel.h"
#include "Debug.h"

// Initialize fixed list of light gestures.
//void (*Neopixel::LIGHTS[2])(uint32_t) = {nullptr, &rainbow};
constexpr void (*Neopixel::LIGHTS[])(uint32_t);

uint8_t Neopixel::_currentIdx = 0;
uint32_t Neopixel::_lastLoop = 0;
Adafruit_NeoPixel_ZeroDMA Neopixel::_strip = Adafruit_NeoPixel_ZeroDMA(NEOPIXEL_COUNT, NEOPIXEL_PIN, NEO_GRBW);

void Neopixel::setup() {
  _strip.begin();
  _strip.setBrightness(5);
  _strip.show();
}

void Neopixel::loop() {
    uint32_t thisLoop = millis();
    uint32_t dt;
    if (_lastLoop) {
        dt = thisLoop - _lastLoop;
    } else {
        dt = 0;
    }
    _lastLoop = thisLoop;

    if (LIGHTS[_currentIdx] != nullptr) {
        LIGHTS[_currentIdx](dt);
    }
}

void Neopixel::setLight(uint8_t lightIdx) {
  // lightIdx soundIdx. Anything outside of the bounds of the array is 0.
  if (lightIdx >= sizeof(LIGHTS) / sizeof(void*)) {
    lightIdx = 0;
  }

  if (_currentIdx != lightIdx) {
    _strip.clear();
    _strip.show();

    _currentIdx = lightIdx;
  }
}

uint8_t Neopixel::getLight() {
  return _currentIdx;
}

void Neopixel::rainbow(uint32_t dt) {
  static uint8_t offset = 0;
  static uint32_t rainbowColors[NEOPIXEL_COUNT] = {16711680, 13578240, 10444800, 7311360, 4177920, 1044480, 56865, 44625,
                                                   32385, 20145, 7905, 1179885, 4325565, 7471245, 10616925, 13762605};

  if (dt > 50) {
    for (uint8_t pix = 0; pix < NEOPIXEL_COUNT; pix++) {
      _strip.setPixelColor((pix + offset) % NEOPIXEL_COUNT, rainbowColors[pix]);
    }
    _strip.show();
    offset++;
  }
}

void Neopixel::crazed(uint32_t wait) {
  uint16_t i;
  uint8_t R, G, B;


  for(i = 0; i < 16; i++){
    if(random(5) < 2){
      R = 255;
      if(random(5) < 2){
        B = 255;
        G = 255;
      }else{
        B = 0;
        G = random(100);
      }
    }else{
      R = 0;
      G = 0;
      B = 0;
    }
    _strip.setPixelColor(i, _strip.Color(R, G, B));
  }
  _strip.show();
  delay(wait);
}


// this is a 2nd ambiant/active code
void Neopixel::randomspiral(uint32_t wait) {
  uint16_t i, j;
  static byte R = 100, G = 100, B = 100, R2 = 100, G2 = 100, B2 = 100;
  byte a;
  
  if(R > 40){
    R = R - random(40);
  }
  
  if(R < 215){
    R = R + random(40);
  }

  if(G > 40){
    G = G - random(40);
  }
  
  if(G < 215){
    G = G + random(40);
  }

  if(B > 40){
    B = B - random(40);
  }
  
  if(B < 215){
    B = B + random(40);
  }

  for(i = 0; i < 16; i++) {
    for(j = 0; j < 16; j++) {
      a = (j + i) % 16;
      if((j + i) < 16) {
        _strip.setPixelColor(a, _strip.Color((R * a / 15), (G * a / 15), (B * a / 15)));
      } else {
        _strip.setPixelColor(a, _strip.Color((R2 * a / 15), (G2 * a / 15), (B2 * a / 15)));
      }
    }
    _strip.show();
    delay(wait);
  }
  R2 = R;
  G2 = G;
  B2 = B;
}


// this is a 3rd ambiant/active code
void Neopixel::alternate(uint32_t wait) {
  uint16_t i, j;
  byte a = 0, b = 0;
  
  byte C = 0, PratioR, PratioG, PratioB;
  //for random colors instead of white set C to 1;
  if(C == 1){
    PratioR = random(1, 10);
    PratioG = random(1, 10);
    PratioB = random(1, 10);
  }else{
    PratioR = 1;
    PratioG = 1;
    PratioB = 1;
  }
  

  for(i = 0; i < 26; i++){
    b = 250 - a;
    for(j = 0; j < 8; j++){
      _strip.setPixelColor((j * 2), _strip.Color(a / PratioR, a / PratioG, a / PratioB));
      _strip.setPixelColor((j * 2) + 1, _strip.Color(b / PratioR, b / PratioG, b / PratioB));
    }
    _strip.show();
    delay(wait);
    a = a + 10;
  }

  for(i = 0; i < 26; i++){
    a = a - 10;
    b = 250 - a;
    for(j = 0; j < 8; j++){
      _strip.setPixelColor((j * 2) + 1, _strip.Color(a / PratioR, a / PratioG, a / PratioB));
      _strip.setPixelColor((j * 2), _strip.Color(b / PratioR, b / PratioG, b / PratioB));
    }
    _strip.show();
    delay(wait);
  }
}

byte rainDropState[16];
byte rainShineState[16];
byte rainDropVolume[16];
byte rainShineVolume[16];

void Neopixel::rainCycle(uint32_t wait) {
  uint16_t i;
  


  for(i = 0; i < 16; i++){
    Rain((rainDropState + i), (rainShineState + i), (rainDropVolume + i), (rainShineVolume + i)); 
  }
  
  for(i = 0; i < 16; i++){
    _strip.setPixelColor(i, _strip.Color(0, 0, *(rainDropVolume + i), *(rainShineVolume + i)));
  }
  
  _strip.show();
  delay(wait);
}

void Neopixel::Rain(byte* rds, byte* rss, byte* rdv, byte* rsv) {
  uint16_t i;
  
  if(*rds == 0){
    if(random(16) <= 1){
      *rds = 1;
    }
  }

  if (*rds == 1){
    i = random(250);
    if ((i + *rdv) >= 250){
      *rdv = 250; 
      *rds = 2;
      *rss = 1;
    } else {
      *rdv = *rdv + i;
    }
  } else if(*rds == 2) {
    i = random(100);
    if ((*rdv - i) <= 0) {
      *rdv = 0; 
      *rds = 0;
    } else {
      *rdv = *rdv - i;
    }

    if(*rss == 1){
      i = random(500);
      if((i + *rsv) >= 250){
        *rsv = 250; 
        *rss = 2;
      }else{
        *rsv = *rsv + i;
      }
    }else if(*rss == 2){
      i = random(250);
      if((*rsv - i) <= 0){
        *rsv = 0; 
        *rss = 0;
      }else{
        *rsv = *rsv - i;
      }
    }
  }
  
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Neopixel::Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return _strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return _strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return _strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

// Slightly different, this makes the rainbow equally distributed throughout
void Neopixel::rainbowCycle(uint32_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 4; j++) { // n cycles of all colors on wheel
    for (i = 0; i < _strip.numPixels(); i++) {
      _strip.setPixelColor(i, Wheel(((i * 256 / _strip.numPixels()) + j) & 255));
    }
    _strip.show();
    delay(wait);
  }
}
