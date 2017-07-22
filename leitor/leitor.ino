//Medição de RPM
//Usando um resistor(ou potenciometro) de 330ohm ligado ao foto diodo
//Usando um resistor de 10k ligado ao fototransistor


const int PinoEntrada = 7;     // O pino 7 recebe está ligado ao coletor do fototransistor
const int ledPin = 13;      // Led do arduino que acende quando o sensor detecta
const int NumPas = 1;    //Número de pás da Hélice
int contagem = 0;            // Conta o número de pulsos no sensor
int PinoState = 1;         // current state of the button
int lastPinoState = 1;     // previous state of the button

        
const long interval = 1000;  //Intervalo de 1000 milissegundos para contar as rotações       
float taxa=0;                //Taxa seria a contagem dentro do  intervalo. RPM=60*taxa

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);   //Led do arduino como saída
  pinMode(PinoEntrada, INPUT); //Pino 7 como entrada
}
unsigned long previousMillis = 0;

void loop() {
  PinoState = digitalRead(PinoEntrada);           //Leitura do Pino 7
  unsigned long currentMillis = millis();         //Tempo que o arduino está ligado
  
  if (PinoState != lastPinoState) {
     if (PinoState == LOW) {
         contagem++;
         digitalWrite(ledPin, HIGH);
       } else {
           digitalWrite(ledPin, LOW);
         } 
    } 
      if (currentMillis - previousMillis >= interval) {
              taxa=(1000*float(contagem))/interval;
             //Serial.print("Contagem:");
             //Serial.println(contagem);
             //Serial.print("Taxa RPM:");
             Serial.println(60*float(taxa)/NumPas);
               previousMillis = currentMillis;
               contagem=0;
           }
  lastPinoState = PinoState;
  
}
