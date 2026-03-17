
/*
Nombre del Proyecto: R.A.B.C.E
Nota: Para usar el Driver L293D es necesario usar la libreria "Adafruit Motor Shield"
Author: Mauricio Rodriguez
Author URI: https://github.com/MauricioRB06
Descripción: Este software  realiza el control del robot R.A.B.C.E mediante un modulo Bluetooth HC-05 a una aplicación móvil.
Version: 1.0
*/

#include <AFMotor.h>
  
// Definicion de Motores
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

int ComandoBluetooth;
int Velocidad = 255;

// Configuracion inicial.
void setup()
{
  Serial.begin(9600);  // Establecer la tasa de baudios del módulo Bluetooth.
}

void loop(){

  if(Serial.available() > 0){

    ComandoBluetooth = Serial.read();

    Detenerse(); //Inicializa los motores detenidos

          if (ComandoBluetooth == 'F'){Adelante();}

          if (ComandoBluetooth == 'B'){Atras();}

          if (ComandoBluetooth == 'L'){Izquierda();}

          if (ComandoBluetooth == 'R'){Derecha();}

          if (ComandoBluetooth == 'I'){ArribaDerecha();}

          if (ComandoBluetooth == 'J'){ArribaIzquierda();}

          if (ComandoBluetooth == 'K'){AbajoDerecha();}

          if (ComandoBluetooth == 'M'){AbajoIzquierda();}

          if (ComandoBluetooth == 'T'){Detenerse();}
  }
}

void Adelante()
{
  motor1.setSpeed(Velocidad); //Definir la velocidaddel motor
  motor1.run(FORWARD); //Girar el motor en el sentido de las agujas del reloj
  motor2.setSpeed(Velocidad); //Definir la velocidaddel motor
  motor2.run(FORWARD); //Girar el motor en el sentido de las agujas del reloj
  motor3.setSpeed(Velocidad); //Definir la velocidaddel motor
  motor3.run(FORWARD); //Girar el motor en el sentido de las agujas del reloj
  motor4.setSpeed(Velocidad); //Definir la velocidaddel motor
  motor4.run(FORWARD); //Girar el motor en el sentido de las agujas del reloj
}

void Atras()
{
  motor1.setSpeed(Velocidad); //Definir la velocidaddel motor
  motor1.run(BACKWARD); //Girar el motor en sentido contrario a las agujas del reloj
  motor2.setSpeed(Velocidad); //Definir la velocidaddel motor
  motor2.run(BACKWARD); //Girar el motor en sentido contrario a las agujas del reloj
  motor3.setSpeed(Velocidad); //Definir la velocidaddel motor
  motor3.run(BACKWARD); //Girar el motor en sentido contrario a las agujas del reloj
  motor4.setSpeed(Velocidad); //Definir la velocidaddel motor
  motor4.run(BACKWARD); //Girar el motor en sentido contrario a las agujas del reloj
}

void Izquierda()
{
  motor1.setSpeed(Velocidad); //Definir la velocidaddel motor
  motor1.run(BACKWARD); //Girar el motor en sentido contrario a las agujas del reloj
  motor2.setSpeed(Velocidad); //Definir la velocidaddel motor
  motor2.run(BACKWARD); //Girar el motor en sentido contrario a las agujas del reloj
  motor3.setSpeed(Velocidad); //Definir la velocidaddel motor
  motor3.run(FORWARD);  //Girar el motor en el sentido de las agujas del reloj
  motor4.setSpeed(Velocidad); //Definir la velocidaddel motor
  motor4.run(FORWARD);  //Girar el motor en el sentido de las agujas del reloj
}

void Derecha()
{
  motor1.setSpeed(Velocidad); //Definir la velocidaddel motor
  motor1.run(FORWARD); //Girar el motor en el sentido de las agujas del reloj
  motor2.setSpeed(Velocidad); //Definir la velocidaddel motor
  motor2.run(FORWARD); //Girar el motor en el sentido de las agujas del reloj
  motor3.setSpeed(Velocidad); //Definir la velocidaddel motor
  motor3.run(BACKWARD); //Girar el motor en sentido contrario a las agujas del reloj
  motor4.setSpeed(Velocidad); //Definir la velocidaddel motor
  motor4.run(BACKWARD); //Girar el motor en sentido contrario a las agujas del reloj
}

void ArribaIzquierda(){
  motor1.setSpeed(Velocidad); //Definir la velocidaddel motor
  motor1.run(FORWARD); //Girar el motor en el sentido de las agujas del reloj
  motor2.setSpeed(Velocidad); //Definir la velocidaddel motor
  motor2.run(FORWARD); //Girar el motor en el sentido de las agujas del reloj
  motor3.setSpeed(Velocidad/3.1);//Definir la velocidaddel motor
  motor3.run(FORWARD); //Girar el motor en el sentido de las agujas del reloj
  motor4.setSpeed(Velocidad/3.1);//Definir la velocidaddel motor
  motor4.run(FORWARD); //Girar el motor en el sentido de las agujas del reloj
}

void ArribaDerecha()
{
  motor1.setSpeed(Velocidad/3.1); //Definir la velocidaddel motor
  motor1.run(FORWARD); //Girar el motor en el sentido de las agujas del reloj
  motor2.setSpeed(Velocidad/3.1); //Definir la velocidaddel motor
  motor2.run(FORWARD); //Girar el motor en el sentido de las agujas del reloj
  motor3.setSpeed(Velocidad); //Definir la velocidaddel motor
  motor3.run(FORWARD); //Girar el motor en el sentido de las agujas del reloj
  motor4.setSpeed(Velocidad); //Definir la velocidaddel motor
  motor4.run(FORWARD); //Girar el motor en el sentido de las agujas del reloj
}

void AbajoIzquierda()
{
  motor1.setSpeed(Velocidad); //Define maximum velocity
  motor1.run(BACKWARD); //Girar el motor en sentido contrario a las agujas del reloj
  motor2.setSpeed(Velocidad); //Define maximum velocity
  motor2.run(BACKWARD); //Girar el motor en sentido contrario a las agujas del reloj
  motor3.setSpeed(Velocidad/3.1); //Define maximum velocity
  motor3.run(BACKWARD); //Girar el motor en sentido contrario a las agujas del reloj
  motor4.setSpeed(Velocidad/3.1); //Define maximum velocity
  motor4.run(BACKWARD); //Girar el motor en sentido contrario a las agujas del reloj
}

void AbajoDerecha()
{
  motor1.setSpeed(Velocidad/3.1); //Definir la velocidaddel motor
  motor1.run(BACKWARD); //Girar el motor en sentido contrario a las agujas del reloj
  motor2.setSpeed(Velocidad/3.1); //Definir la velocidaddel motor
  motor2.run(BACKWARD); //Girar el motor en sentido contrario a las agujas del reloj
  motor3.setSpeed(Velocidad); //Definir la velocidaddel motor
  motor3.run(BACKWARD); //Girar el motor en sentido contrario a las agujas del reloj
  motor4.setSpeed(Velocidad); //Definir la velocidaddel motor
  motor4.run(BACKWARD); //Girar el motor en sentido contrario a las agujas del reloj
}

void Detenerse()
{
  motor1.setSpeed(0); //Definir la velocidaddel motor
  motor1.run(RELEASE); //Detener el motor al soltar el botón
  motor2.setSpeed(0); //Definir la velocidaddel motor
  motor2.run(RELEASE); //Detener el motor al soltar el botón
  motor3.setSpeed(0); //Definir la velocidaddel motor
  motor3.run(RELEASE); //Detener el motor al soltar el botón
  motor4.setSpeed(0); //Definir la velocidaddel motor
  motor4.run(RELEASE); //Detener el motor al soltar el botón
}
