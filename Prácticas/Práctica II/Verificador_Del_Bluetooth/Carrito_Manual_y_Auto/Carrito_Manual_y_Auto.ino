int tiempo = 0;
int distancia = 0;
char estado = ' ';
bool modoAutomatico = false;

void setup() {
  // Configuración de los pines de los motores y del sensor ultrasónico
  pinMode(50, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(53, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(49, INPUT);
  Serial.begin(9600);
  Serial2.begin(9600);
}

void avanzar() {
  digitalWrite(50, HIGH);
  digitalWrite(51, LOW);
  digitalWrite(52, HIGH);
  digitalWrite(53, LOW);
}

void derecha() {
  digitalWrite(50, LOW);
  digitalWrite(51, HIGH);
  digitalWrite(52, HIGH);
  digitalWrite(53, LOW);
}

void izquierda() {
  digitalWrite(50, HIGH); // IZQUIERDA
  digitalWrite(51, LOW);
  digitalWrite(52, LOW);
  digitalWrite(53, HIGH);
}

void reversa() {
  digitalWrite(50, LOW); 
  digitalWrite(51, HIGH);
  digitalWrite(52, LOW);
  digitalWrite(53, HIGH);
}

void parar() {
  digitalWrite(50, LOW); 
  digitalWrite(51, LOW);
  digitalWrite(52, LOW);
  digitalWrite(53, LOW);
}

void medirDistancia() {
  // Dispara el pulso en el pin Trig
  digitalWrite(48, HIGH);
  delayMicroseconds(10);
  digitalWrite(48, LOW);

  // Lee el pin Echo, y calcula la distancia
  tiempo = pulseIn(49, HIGH, 300000); // espera
  distancia = (tiempo / 58);
  //Serial.println(distancia);
}

void loop() {
  medirDistancia();

  if (Serial2.available() > 0) {
    estado = Serial2.read();
    if (estado == 'm') {
      modoAutomatico = !modoAutomatico;
      parar(); // Detener el carrito al cambiar de modo
      Serial.println(modoAutomatico ? "Modo Automático Activado" : "Modo Manual Activado");
    }
  }

  if (modoAutomatico) {
    // Modo automático
    if (distancia <= 20) {
      reversa();
      delay(500);
      derecha();
      delay(500);
      avanzar();
    } else {
      avanzar();
    }
  } else {
    // Modo manual
    switch (estado) {
      case 'a':
        izquierda();
        break;
      case 'w':
        avanzar();
        break;
      case 'd':
        derecha();
        break;
      case 's':
        reversa();
        break;
      case 'p':
        parar();
        break;
      default:
        parar();  // Detener el carrito si no hay comando válido
        break;
    }
  }
}
