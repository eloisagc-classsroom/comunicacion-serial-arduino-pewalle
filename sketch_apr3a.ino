//VARIABLES
const byte ledPin[] = {2,3,4,5};
int ledPinLength = sizeof(ledPin) / sizeof(ledPin[0]);
int numBlinks; //variable cuyo valor indicara el usuario
int orden; // variable para definir el orden

//PREPARAR SALIDA
void setup()
{
  	Serial.begin(9600);
  	for (int i=0; i<ledPinLength; i++) {
   		pinMode(ledPin[i], OUTPUT);  //los preparamos para salida
 	}
}

//LOOP PRINCIPAL
void loop()
{
  Serial.println("Si quieres el conteo de forma ascedente ingresa un '0'. Si quieres el conteo de forma descentende marca un '1'");
  while(Serial.available() == 0)
  { // Espera hasta recibir la entrada del usuario en la consola
  }
  orden = Serial.parseInt(); //Lee el dato de la consola y lo almacena en la variable
  //Ascendente

  while (Serial.available() > 0){ // Limpieza de buffer
    Serial.read();
  }

  if(orden == 0){
  for (int num = 0; num < Exponente(ledPinLength); num++) { // Cuenta de 0 a 15
    Serial.print("El numero en decimal es: ");
    Serial.println(num);
    String s = "";
    for (int i = 0; i < ledPinLength; i++) {
      if (num & (1 << i)) { // Comprueba si el bit en la posición i está encendido
        digitalWrite(ledPin[i], HIGH); // Enciende el LED si el bit está encendido
        s += 1;
      } else {
        digitalWrite(ledPin[i], LOW); // Apaga el LED si el bit está apagado
        s += 0;
      }
    }
    Serial.print("El numero en binario es: ");
	Serial.println(invertirCadena(s));
    Serial.println("-------------------");
    delay(500); // Espera un segundo antes de mostrar el siguiente número
  }
  orden = int("");
  }
  
  //Descendente
  else if (orden == 1){
  for (int num = Exponente(ledPinLength) - 1; num >= 0; num--) {
    Serial.print("El numero en decimal es: ");
    Serial.println(num);
    String s = "";
    for (int i = 0; i < ledPinLength; i++) {
      if (num & (1 << i)) {
        digitalWrite(ledPin[i], HIGH);
        s += 1;
      } else {
        digitalWrite(ledPin[i], LOW);
        s += 0;
      }
    }
	Serial.print("El numero en binario es: ");
	Serial.println(invertirCadena(s));
    Serial.println("-------------------");
    delay(500); // Espera un segundo
  }
  }
  else{
  Serial.println("Intruccion incorrecta");}
}

int Exponente(int num){
  int resultado = 1;
  for(int i = 0 ; i<num ; i++){
    resultado = resultado * 2;
  }
  return resultado;
}
    String invertirCadena(String s){
      String temporal = "";
      for (int m = s.length() - 1; m >= 0; m--)
        temporal += s[m];
      return temporal;
    }