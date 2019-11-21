/*             AUTHOR: Anas Ahmed
              Hackerspace Karachi
        Website:www.hackerspacekarachi.com
       Facebook: fb.com/hackerspacekarachi

*/



#include <FastLED.h>

volatile byte state = LOW;

const byte Switch = 2;      //Attach HIGH END of the switch to PIN D2
int potvalue;
int ldrvalue;

#define NUM_LEDS 20         //Define no. of LEDS
#define DATA_PIN 7          // Connect Data pin of led strip to D7
#define INT1 3              // Attach input 1 to D3
#define INT2 4              //Attach inout 2 to D4
#define potPin A1           //Potpin to A1
#define ldrPin A2           // LDR on end to A2 
//#define Rand 8

CRGB leds[NUM_LEDS];
int LightIntensityValue = 50;   //Value of light intensity you want to trigger the code
int a = 0;
int b = 0;
int wait = 100;
bool check = false;       // for case 1
bool check1 = false;      // for case 2
bool checks2 = false;     // for case 3
bool checks3 = false;     // for case 4

void setup() {
  FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS);
  pinMode(INT1, INPUT_PULLUP);
  pinMode(INT2, INPUT_PULLUP);
  //pinMode(Rand, INPUT_PULLUP);
  pinMode(Switch, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(Switch), switchOn, CHANGE);
  Serial.begin(9600);


}

void loop() {
  /*ldr();
    if (ldrvalue < LightIntensityValue) {
    step2();
    }
    if (state == LOW && ldrvalue >= LightIntensityValue) {
    pot();


    fzul();
    FastLED.setBrightness(potvalue);
  */
  int   IN1 = digitalRead(INT1);
  int   IN2 = digitalRead(INT2);

  if (IN1 == HIGH && checks3 == false) {
    int flag3 = 0;
    delay(200);
    for (int i = 0; i < NUM_LEDS; i++) {
      if (IN2 == HIGH) {
        case3();
        
        int flag3 = 1;
      delay(200);}
      if (flag3 == 0) {
        leds[i] = CRGB::Blue;
        FastLED.show();
      delay(200);}
    }
  }
}





void case1a() {
  for (int i = 1; i <= NUM_LEDS - 2 ; i++) {
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(wait);
  }
}

void case2a() {
  for (int i = NUM_LEDS - 2; i >= 1 ; i--) {
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(wait);
  }
}

void case1b() {
  for (int i = 1; i <= NUM_LEDS - 2; i++) {
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(wait);
  }
}

void case2b() {
  for (int i = NUM_LEDS - 2; i >= 1 ; i--) {
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(wait);
  }
}

void case3a() {
  //delay(100);
  for (int i = 0; i < NUM_LEDS / 2; i++) {
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(wait);
  }

}
void case3b() {
  //delay(100);
  for (int i = NUM_LEDS ; i >= NUM_LEDS / 2 ; i--) {
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(wait);
  }

}

void case4a() {
  delay(100);
  for (int i = 0; i < NUM_LEDS / 2; i++) {
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(wait);
  }

}
void case4b() {
  delay(100);
  for (int i = NUM_LEDS ; i >= NUM_LEDS / 2; i--) {
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(wait);
  }

}
void case5b() {
  delay(100);
  for (int i = 0; i < NUM_LEDS / 2; i++) {
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(wait);
  }

}
void case5a() {
  delay(100);
  for (int i = NUM_LEDS ; i >= NUM_LEDS / 2; i--) {
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(wait);
  }

}

void case6b() {
  delay(100);
  for (int i = 0; i < NUM_LEDS / 2; i++) {
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(wait);
  }

}
void case6a() {
  delay(100);
  for (int i = NUM_LEDS ; i >= NUM_LEDS / 2; i--) {
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(wait);
  }

}


void zero() {
  delay(100);
  for (int i = 1; i < NUM_LEDS - 1; i++) {
    leds[i] = CRGB::Black;
  } FastLED.show();
}


void switchOn() {
  FastLED.setBrightness(50);
  state = ! state;
  if (state == HIGH) {
    step1();
  }
  else if (state == LOW) {
    step2();
  }
}

void step1() {
  for (int i = NUM_LEDS; i >= 0 ; i--) {
    leds[i] = CRGB::White;
    Serial.print("Switch State = ");
    Serial.println(state);

  } FastLED.show();
}


void step2() {
  for (int i = NUM_LEDS; i >= 0 ; i--) {
    leds[i] = CRGB::Black;
    Serial.print("Switch State = ");
    Serial.println(state);

  } FastLED.show();
}


void pot() {
  potvalue = analogRead(potPin);
  potvalue = map(potvalue, 0, 1023, 150, 0);
  Serial.print("Brightness = ");
  Serial.println(potvalue);
}


void ldr() {
  ldrvalue = analogRead(ldrPin);

  ldrvalue = map(ldrvalue, 0, 1023, 255, 0);
  Serial.print("ldr Value = ");
  Serial.println(ldrvalue);
}

void case3() {

  for (int i = NUM_LEDS - 2; i >= 7; i--) {
    leds[i] = CRGB::Blue;
    FastLED.show();
    if (i <= 14) {
      leds[15 - i] = CRGB::Blue;
      FastLED.show();
    }
    delay(200);
  }
}

void case4() {

  for (int i = NUM_LEDS - 2 ; i >= 7; i--) {
    leds[i] = CRGB::Black;
    FastLED.show();
    if (i <= 14) {
      leds[15 - i] = CRGB::Black;
      FastLED.show();
    }
    delay(200);
  }
}


void fzul() {
  for (int i = 0; i < 1; i ++) {
    leds[i] = CRGB::Green;
    FastLED.show();
    leds[NUM_LEDS - 1] = CRGB::Green;
    FastLED.show();
  }
}
