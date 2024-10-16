#define p_R_1 13
#define p_G_1 11
#define p_B_1 12

#define p_R_2 10
#define p_G_2 8
#define p_B_2 9

#define p_R_3 7
#define p_G_3 5
#define p_B_3 6

bool estadoLED = true; 

void setup() {
  Serial.begin(9600);
  pinMode(p_R_1, OUTPUT);
  pinMode(p_G_1, OUTPUT);
  pinMode(p_B_1, OUTPUT);
  
  pinMode(p_R_2, OUTPUT);
  pinMode(p_G_2, OUTPUT);
  pinMode(p_B_2, OUTPUT);
  
  pinMode(p_R_3, OUTPUT);
  pinMode(p_G_3, OUTPUT);
  pinMode(p_B_3, OUTPUT);
}

void controlarLEDs(char opt) {
  if (estadoLED) {
    switch (opt) {
      case '1':
        led_1(0, 255, 0);   // LED 1 en verde
        led_2(255, 0, 0);   // LED 2 en rojo
        led_3(255, 0, 0);   // LED 3 en rojo
        break;
      case '2':
        led_1(255, 0, 0);   // LED 1 en rojo
        led_2(0, 255, 0);   // LED 2 en verde
        led_3(255, 0, 0);   // LED 3 en rojo
        break;
      case '3':
        led_1(255, 0, 0);   // LED 1 en rojo
        led_2(255, 0, 0);   // LED 2 en rojo
        led_3(0, 255, 0);   // LED 3 en verde
        break;
    }
  } else {
    // Apagar todos los LEDs
    led_1(0, 0, 0);
    led_2(0, 0, 0);
    led_3(0, 0, 0);
  }
}

void led_1(int red, int green, int blue) {
  analogWrite(p_R_1, red);
  analogWrite(p_G_1, green);
  analogWrite(p_B_1, blue);
}

void led_2(int red, int green, int blue) {
  analogWrite(p_R_2, red);
  analogWrite(p_G_2, green);
  analogWrite(p_B_2, blue);
}

void led_3(int red, int green, int blue) {
  analogWrite(p_R_3, red);
  analogWrite(p_G_3, green);
  analogWrite(p_B_3, blue);
}

void loop() {
  if (Serial.available() > 0) {
    char opt = Serial.read();

   
    if (opt == '1' || opt == '2' || opt == '3') {
      controlarLEDs(opt); 
    }
  }
}