int waterpump = 5; //waterpump pin - digiral pin

int sensorpin = A0; //moisture pin - analog pin
int humidvalue = 0; //value of moisture

void setup() {
  pinMode(waterpump, OUTPUT); //set waterpump(pin 5) as output
  digitalWrite(waterpump, LOW); //set waterpump as off

  Serial.begin(9600);

}

//Automatic watering plant system
void wateringPlant(){

  humidvalue = analogRead(sensorpin); //get moisture value from sensorpin(pin A0)
  Serial.println(humidvalue); //Show moister value in Serial Monitor

  //condition for if soil dry, pump will start working
  if(humidvalue > 500){
    digitalWrite(waterpump, HIGH); //turn pump on
    } else {
     digitalWrite(waterpump, LOW); //turn pump off
    }
  
  }

void loop() {
  wateringPlant();
  delay(2000); // delay 2 sec for checking

}
