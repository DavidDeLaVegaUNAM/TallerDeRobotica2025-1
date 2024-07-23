char estado = 0;

void setup() {
  Serial.begin(9600);  // Inicializa la comunicación serial con la computadora
  Serial1.begin(9600); // Inicializa la comunicación serial con el módulo Bluetooth
}

void loop() {
  if (Serial1.available() > 0) {
    estado = Serial1.read();    // Lee el valor del módulo Bluetooth
    Serial.println(estado);     // Imprime el valor en el monitor serie de la computadora
  }
}
