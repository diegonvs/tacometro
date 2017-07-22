void setup(){
	Serial.begin(9600);
}

void loop(){
	for(int i;i < 2;i++){
		Serial.println("0001");
		delay(1000);
	}
	for(int j;j < 2;j++){
		Serial.println("1000");
		delay(1000);
	}

}
