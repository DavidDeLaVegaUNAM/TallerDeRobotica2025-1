//                                                                                           Para declarar una variable necesitamos hacerlo en el formato:
// Tipo nombre = Valor

int tiempo = 0;
int distancia = 0;


void setup() {
  // Aquí definimos cada que pin (número) vamos a usar
  // Y de que tipo es (Entrada/Salida)
  pinMode(48,OUTPUT); // Trigger: Emite sonido
  pinMode(49,INPUT);  // Echo: Recibe sonido 
  pinMode(50,OUTPUT); // Rueda Izquierda
  pinMode(51,OUTPUT); // Rueda Izquierda
  pinMode(52,OUTPUT); // Rueda Derecha
  pinMode(53,OUTPUT); // Rueda Derecha
  Serial.begin(9600); // Con esto vamos a verificar si nuestro sensor recibe datos.

void avanzar(){
  digitalWrite(50,HIGH);
  digitalWrite(51,LOW);
  digitalWrite(52,HIGH);
  digitalWrite(53,LOW);  
}


void derecha(){
  digitalWrite(50,LOW);
  digitalWrite(51,LOW);
  digitalWrite(52,HIGH);
  digitalWrite(53,LOW);  
}

void izquierda(){
  digitalWrite(50,HIGH);
  digitalWrite(51,LOW);
  digitalWrite(52,LOW);
  digitalWrite(53,HIGH);
}

void reversa(){
  digitalWrite(50,LOW);
  digitalWrite(51,HIGH);
  digitalWrite(52,LOW);
  digitalWrite(53,HIGH);
}

void deternese(){
  delay(1000);
}
void loop() {
  
  // ACTIVIDAD 1: Rutina (Rutina para que el robot "baile")

  /*
  avanzar();
  detenerse()
  reversa();
  izquierda();
  derecha();
  detenerse();
  */
  
  
  // ACTIVIDAD 2: Probando detector, medir distancia.
  
  // digitalWrite(48,HIGH); // Con esto prendemos el sensor
  // delayMicroseconds(10); // 
  // digitalWrite(48,LOW); // Con esto apagamos el sensor
  // tiempo = pulseIn(49, HIGH, 300000); // fORMA DE ESPERAR
  // distancia = (tiempo/58)
  // Serial.printLn(distancia)


  // ACTIVIDAD 3: Robot chocón.
  /* if (distancia <= 40 ) : {
  avanzar();
  }
  else{
  reversa();
  derecha();
  izquierda();
  }
