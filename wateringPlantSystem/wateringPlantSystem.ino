int signalLED = 5; // pin ไฟแสดงว่าขาดน้ำ
int sensorpin = A0; // pin วัดความชื่นดิน
const int buzzer = 2; // pin ลำโพง

void setup() {
  pinMode(signalLED, OUTPUT); // set ไฟ(pin 5) เป็น output
  digitalWrite(signalLED, LOW); // set ไฟให้ปิด
  
  pinMode(buzzer, OUTPUT); // set ลำโพง(pin 2) เป็น output

  Serial.begin(9600);

}

// song
void song(){
  int melody[] = {
  392, 392, 440, 440, 467, 467, 440, // Twinkle, twinkle, little star
  392, 392, 440, 440, 467, 467, 440, // How I wonder what you are
  392, 392, 440, 440, 467, 467, 440, // Up above the world so high
  392, 392, 440, 440, 467, 467, 440, // Like a diamond in the sky
  392, 392, 440, 440, 467, 467, 440, // Twinkle, twinkle, little star
  392, 392, 440, 440, 467, 467, 440  // How I wonder what you are
  };

  for (int i = 0; i < sizeof(melody) / sizeof(int); i++) {
    tone(buzzer, melody[i]);
    delay(400);
    noTone(buzzer);
    delay(50); // Small pause between notes
  }

  delay(2000); // Pause before repeating the song
  
}


//watering plant system
void wateringPlant(){

  int moisturevalue = analogRead(sensorpin); // รับค่าความชิ้นจาก analog pin 0
  Serial.println(moisturevalue); // แสดงค่าความชื่นใบน Serial Monitor

  // เงื่อนไข ถ้าความชื่น > 500, เสียงจะดังทุกๆ 2 sec
  if(moisturevalue > 500){
    tone(buzzer, 1000); // เปิดเสียง
    delay(1000); // delay 1 sec
    noTone(buzzer); // ปิดเสียง
    delay(1000); // delay 1 sec
    digitalWrite(signalLED, HIGH); // เปิดไฟ
    } else {
      digitalWrite(signalLED, LOW); // ปิดไฟ
  }

}

void loop() {
  wateringPlant(); // เรียกใช้ wateringPlant
  delay(2000); // delay 2 sec for checking
  song();

}
