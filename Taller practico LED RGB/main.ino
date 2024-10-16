#define p_R_1 6
#define p_G_1 3
#define p_B_1 5

void setup() {
  Serial.begin(9600);
  
  pinMode(p_R_1, OUTPUT);
  pinMode(p_G_1, OUTPUT);
  pinMode(p_B_1, OUTPUT);
}

void led_1(int red, int green, int blue) {
  analogWrite(p_R_1, red);
  analogWrite(p_G_1, green);
  analogWrite(p_B_1, blue);
}

void loop() {
  if (Serial.available() > 0) {
    
    Serial.println("Introduce el valor para el color ROJO (0-255):");
    while (!Serial.available());  
    int r = Serial.parseInt();   

    
    Serial.println("Introduce el valor para el color VERDE (0-255):");
    while (!Serial.available());  
    int g = Serial.parseInt();    
    
    
    Serial.println("Introduce el valor para el color AZUL (0-255):");
    while (!Serial.available());  
    int b = Serial.parseInt();    

   
    r = constrain(r, 0, 255);
    g = constrain(g, 0, 255);
    b = constrain(b, 0, 255);

    led_1(r, g, b);
    
    Serial.print("Valores configurados - Rojo: ");
    Serial.print(r);
    Serial.print(", Verde: ");
    Serial.print(g);
    Serial.print(", Azul: ");
    Serial.println(b);
  }
}