#include <AFMotor.h>

// Link de la librería: https://www.prometec.net/wp-content/uploads/2015/03/adafruit-Adafruit-Motor-Shield-library-8119eec.zip
// Robot para curso de San Vicente 2021

AF_DCMotor Motor1(3);
AF_DCMotor Motor2(4);

void setup()
{
  Serial.begin(9600);
  Motor1.setSpeed(200);
  Motor2.setSpeed(200);
  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
}

void loop() {
  while (Serial.available() > 0) {
    switch (Serial.read()) {
      case 'a': { //Adelante
          Motor1.run(FORWARD);
          Motor2.run(FORWARD);
          break;
        }
      case 'b': { //Atras
          Motor1.run(BACKWARD);
          Motor2.run(BACKWARD);
          break;
        }
      case 'c': { //Izquierda
          Motor1.run(BACKWARD);
          Motor2.run(FORWARD);
          break;
        }
      case 'd': { //Derecha
          Motor1.run(FORWARD);
          Motor2.run(BACKWARD);
          break;
        }
      case 'e': { //IzquierdaAdelante
          Motor1.run(FORWARD);
          break;
        }
      case 'f': { //IzquierdaAtras
          Motor1.run(BACKWARD);
          break;
        }
      case 'g': { //DerechaAdelante
          Motor2.run(FORWARD);
          break;
        }
      case 'h': { //DerechaAtras
          Motor2.run(BACKWARD);
          break;
        }
      case 'i': { //Detener
          Motor1.run(RELEASE);
          Motor2.run(RELEASE);
          break;
        }
      case 'o': {
          Serial.println("Datos Recibidos");
          break;
        }
    }
  }
}
