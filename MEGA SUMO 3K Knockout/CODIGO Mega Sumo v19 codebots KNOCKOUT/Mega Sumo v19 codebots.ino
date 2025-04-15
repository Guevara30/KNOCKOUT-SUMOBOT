//     Sumobot v19 codebots.ino         //

//        Variables_ and_Instruccines   //

int sensor_e18_izquierdo =12; //Sensor delantero derecho  
int sensor_e18_derecho =11;   //Sensor delantero izquierdo
int sensor_tcr_izquierdo= A0; //Sensor lateral dereho 
int sensor_tcr_derecho=A1;    //Sensor lateral izquierdo

//        Salidas                      //

int PWM=155;      // Ajuste de velocidad
int PWM_M1=6;     // Señal de pwm para driver
int PWM_M2=5;     // Señal de pwm para driver
int MOTOR_1=7;    // Pulsos para los motores
int MOTOR_1_=8;   // Pulsos para los motores
int MOTOR_2=4;    // Pulsos para los motores
int MOTOR_2_=9;   // Pulsos para los motores

int ON =5;        // Tiempo en segundos
int PWM=155;      // Ajuste de velocidad
int TIEMPO=0;
int EST=0;
void setup() 
{
//SALIDAS 
pinMode(9,OUTPUT); //CONFIGURACION DE SALIDA
pinMode(8,OUTPUT); //CONFIGURACION DE SALIDA
pinMode(7,OUTPUT); //CONFIGURACION DE SALIDA
pinMode(6,OUTPUT); //CONFIGURACION DE SALIDA
pinMode(5,OUTPUT); //CONFIGURACION DE SALIDA
pinMode(4,OUTPUT); //CONFIGURACION DE SALIDA

//SENSORES_
pinMode(sensor_e18_derecho,INPUT); //CONFIGURACION DE SENSORES
pinMode(sensor_e18_izquierdo,INPUT); //CONFIGURACION DE SENSORES
pinMode(sensor_tcr_derecho,INPUT); //CONFIGURACION DE SENSORES
pinMode(sensor_tcr_izquierdo,INPUT); //CONFIGURACION DE SENSORES
Serial.begin(115200);
}

void loop() 
{
if(Serial.available()>0) {       
estado = Serial.read();
}

if(estado=='c')
{
Serial.println("ALTO"); 
}
TIEMPO=PWM/2;
//CONTROL_INALAMBRICO
//SENSORES_CENTRALES
SENSOR_A=digitalRead(A4);
SENSOR_B=digitalRead(2); 
SENSOR_LA=digitalRead(A5);
SENSOR_LB=digitalRead(3);
SENSOR_LINEA_A=digitalRead(A2); 
SENSOR_LINEA_B=digitalRead(A3);
SENSOR_LINEA_C=digitalRead(A0);
SENSOR_LINEA_D=digitalRead(A1);

if(CONTROL_A==LOW && CONTROL_B==HIGH && CONTROL_C==LOW && CONTROL_D==LOW && MODO==0)
{
estado='a'; 
//ARRANQUE LADO DERECHO
if(digitalRead(13)==LOW)
{

analogWrite(PWM_M1,255);
delay(7000);
analogWrite(PWM_M1,TIEMPO);
analogWrite(PWM_M2,TIEMPO);
digitalWrite(MOTOR_1,LOW);
digitalWrite(MOTOR_1_,HIGH);
digitalWrite(MOTOR_2,HIGH);
digitalWrite(MOTOR_2_,LOW);
delay(7000);
digitalWrite(MOTOR_1,LOW);
digitalWrite(MOTOR_1_,LOW);
digitalWrite(MOTOR_2,LOW);
digitalWrite(MOTOR_2_,LOW);
MODO=1; 
}  
}


if(CONTROL_A== HIGH && CONTROL_B==LOW && CONTROL_C==LOW && CONTROL_D==LOW && MODO==0)
{
estado='a'; 
//ARRANQUE LADO DERECHO
if(digitalRead(11)==LOW)
{
analogWrite(PWM_M1,255);
delay(7000);
analogWrite(PWM_M1,TIEMPO);
analogWrite(PWM_M2,TIEMPO);
digitalWrite(MOTOR_1,HIGH);
digitalWrite(MOTOR_1_,LOW);
digitalWrite(MOTOR_2,HIGH);
digitalWrite(MOTOR_2_,LOW);
delay(7000);
digitalWrite(MOTOR_1,LOW);
digitalWrite(MOTOR_1_,LOW);
digitalWrite(MOTOR_2,LOW);
digitalWrite(MOTOR_2_,LOW);
MODO=2; 
}  
}

if(CONTROL_A==LOW && CONTROL_B==LOW && CONTROL_C==LOW && CONTROL_D==HIGH && MODO==0)
{
estado='a'; 
analogWrite(PWM_M1,255);

//ARRANQUE DERECHO
if(digitalRead(12)==LOW&&PWM==255)
{
analogWrite(PWM_M1,255);
delay(7000);
analogWrite(PWM_M1,PWM);
analogWrite(PWM_M2,PWM);
digitalWrite(MOTOR_1,HIGH);
digitalWrite(MOTOR_1_,LOW);
digitalWrite(MOTOR_2,HIGH);
digitalWrite(MOTOR_2_,LOW);
delay(7000);
digitalWrite(MOTOR_1,LOW);
digitalWrite(MOTOR_1_,LOW);
digitalWrite(MOTOR_2,LOW);
digitalWrite(MOTOR_2_,LOW);
MODO=3; 
}  

if(CONTROL_A==HIGH && CONTROL_B==LOW && CONTROL_C==LOW && CONTROL_D==HIGH && MODO==0)
{
estado='a'; 
analogWrite(PWM_M1,255);
//ARRANQUE DETRAS
if(digitalRead(12)==LOW&&PWM==155)
{
analogWrite(ON,PWM);
delay(7000);
analogWrite(PWM_M1,PWM);
analogWrite(PWM_M2,PWM);
digitalWrite(MOTOR_1,HIGH);
digitalWrite(MOTOR_1_,LOW);
digitalWrite(MOTOR_2,LOW);
digitalWrite(MOTOR_2_,HIGH);
delay(7000);
digitalWrite(MOTOR_1,LOW);
digitalWrite(MOTOR_1_,LOW);
digitalWrite(MOTOR_2,LOW);
digitalWrite(MOTOR_2_,LOW);
MODO=3;
} 
}


if(CONTROL_A==LOW && CONTROL_B==HIGH && CONTROL_C==HIGH && CONTROL_D==LOW && MODO==0)
{
analogWrite(PWM_M1,255);
delay(3000);
analogWrite(PWM_M1,0);
delay(3000);
Serial.println("PWM ARRIBA");
PWM=255;  
}

if(CONTROL_A==HIGH && CONTROL_B==LOW && CONTROL_C==HIGH && CONTROL_D==LOW && MODO==3)
{
analogWrite(PWM_M1,155);
delay(2000);
analogWrite(PWM_M1,155);
delay(2000);
Serial.println("PWM BAJO");
PWM=155;  
}

if(CONTROL_C==HIGH)
{
MODO=0;
estado='d'; 
} 


if(CONTROL_C==0 && CONTROL_A==0 && MODO==3)
{
Serial.println("ARRANQUE DIRECTO AVANZAR");


if(SENSOR_A==0 && SENSOR_B==0 && SENSOR_LA==1 && SENSOR_LB==1 && SENSOR_LINEA_A==1 && SENSOR_LINEA_B==1 && SENSOR_LINEA_C==1 && SENSOR_LINEA_D==1)  
{
Serial.println("ATAQUE CENTRAL");   
analogWrite(PWM_M1,TIEMPO);
analogWrite(PWM_M2,TIEMPO);
digitalWrite(MOTOR_1,HIGH);
digitalWrite(MOTOR_1_,LOW);
digitalWrite(MOTOR_2,HIGH);
digitalWrite(MOTOR_2_,LOW);
}

if(SENSOR_A==0&&SENSOR_B==0&&SENSOR_LINEA_A==0&&SENSOR_LINEA_B==0)  
{
Serial.println("ATAQUE CENTRAL Y LADOS");   
analogWrite(PWM_M1,PWM);
analogWrite(PWM_M2,PWM);
digitalWrite(MOTOR_1,HIGH);
digitalWrite(MOTOR_1_,LOW);
digitalWrite(MOTOR_2,HIGH);
digitalWrite(MOTOR_2_,LOW);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

if(SENSOR_A==1&&SENSOR_B==1&&SENSOR_LINEA_A==1&&SENSOR_LINEA_B==0)  
{
Serial.println("ATAQUE CENTRAL DETECTO LINEA DELANTERA A");   
analogWrite(PWM_M1, PWM);
analogWrite(PWM_M2,PWM);
digitalWrite(MOTOR_1,LOW);
digitalWrite(MOTOR_1_,HIGH);
digitalWrite(MOTOR_2,LOW);
digitalWrite(MOTOR_2_,HIGH);
}

if(SENSOR_A==0&&SENSOR_B==0&&SENSOR_LINEA_A==1&&SENSOR_LINEA_B==0)  
{
Serial.println("ATAQUE CENTRAL DETECTO LINEA DELANTERA A 3 ");   
analogWrite(PWM_M1,TIEMPO);
analogWrite(PWM_M2,TIEMPO);
digitalWrite(MOTOR_1,LOW);
digitalWrite(MOTOR_1_,HIGH);
digitalWrite(MOTOR_2,LOW);
digitalWrite(MOTOR_2_,HIGH);
delay(500);
}

if(SENSOR_A==1&&SENSOR_B==1&&SENSOR_LINEA_A==1&&SENSOR_LINEA_B==0)  
{
Serial.println("DETECTO LINEA DELANTERA A SIN DETECTAR");   
analogWrite(PWM_M1,TIEMPO);
analogWrite(PWM_M2,TIEMPO);
digitalWrite(MOTOR_1,LOW);
digitalWrite(MOTOR_1_,HIGH);
digitalWrite(MOTOR_2,LOW);
digitalWrite(MOTOR_2_,HIGH);
delay(500);


}

if(SENSOR_A==1&&SENSOR_B==1&&SENSOR_LINEA_A==0&&SENSOR_LINEA_B==1)  
{
Serial.println("DETECTO LINEA DELANTERA B");   
analogWrite(PWM_M1,TIEMPO);
analogWrite(PWM_M2,TIEMPO);
digitalWrite(MOTOR_1,LOW);
digitalWrite(MOTOR_1_,HIGH);
digitalWrite(MOTOR_2,LOW);
digitalWrite(MOTOR_2_,HIGH);
delay(500);
}



if(SENSOR_A==0&&SENSOR_B==0&&SENSOR_LINEA_A==0&&SENSOR_LINEA_B==1)  
{
Serial.println("DETECTO LINEA DELANTERA B 3 ");   
analogWrite(PWM_M1,TIEMPO);
analogWrite(PWM_M2,TIEMPO);
digitalWrite(MOTOR_1,LOW);
digitalWrite(MOTOR_1_,HIGH);
digitalWrite(MOTOR_2,LOW);
digitalWrite(MOTOR_2_,HIGH);
delay(500);
}

if(SENSOR_A==0&&SENSOR_B==0&&SENSOR_LINEA_A==1&&SENSOR_LINEA_B==1)  
{
Serial.println("DETECTO LINEA DELANTERA A Y B 3 ");   
analogWrite(PWM_M1,TIEMPO);
analogWrite(PWM_M2,TIEMPO);
digitalWrite(MOTOR_1,LOW);
digitalWrite(MOTOR_1_,HIGH);
digitalWrite(MOTOR_2,LOW);
digitalWrite(MOTOR_2_,HIGH);
delay(500);
}

if(SENSOR_A==1&&SENSOR_B==1&&SENSOR_LINEA_A==0&&SENSOR_LINEA_B==1)  
{
Serial.println("DETECTO LINEA DELANTERA B SIN DETECTAR OPONENTE");   
analogWrite(PWM_M1,TIEMPO);
analogWrite(PWM_M2,TIEMPO);
digitalWrite(MOTOR_1,LOW);
digitalWrite(MOTOR_1_,HIGH);
digitalWrite(MOTOR_2,LOW);
digitalWrite(MOTOR_2_,HIGH);
delay(500);


}

if(SENSOR_A==1&&SENSOR_B==1&&SENSOR_LINEA_A==1&&SENSOR_LINEA_B==1)  
{
Serial.println("DETECTO LINEA A Y B SIN DETECTAR");   
analogWrite(PWM_M1,TIEMPO);
analogWrite(PWM_M2,TIEMPO);
digitalWrite(MOTOR_1,LOW);
digitalWrite(MOTOR_1_,HIGH);
digitalWrite(MOTOR_2,LOW);
digitalWrite(MOTOR_2_,HIGH);
delay(500);


}

}

if(CONTROL_C==0&&CONTROL_A==0&&MODO==1)
{
Serial.println("ARRANQUE LADO A");


}

if(CONTROL_C==0&&CONTROL_A==0&&MODO==2)
{
Serial.println("ARRANQUE LADO B");

}

//MODO APAGADO DEL SUMO
if(CONTROL_A==0&&MODO==0&&CONTROL_B==0&&CONTROL_C==0&&CONTROL_D==0)
{

analogWrite(PWM_M1,0);
analogWrite(PWM_M2,0);
digitalWrite(MOTOR_1,LOW);
digitalWrite(MOTOR_1_,LOW);
digitalWrite(MOTOR_2,LOW);
digitalWrite(MOTOR_2_,LOW);

}


}
}