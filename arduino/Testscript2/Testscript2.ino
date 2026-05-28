/*
Testscript V2 code project opkomende technologiën
28/05/2026
door Axelle De Bleser

*/

//variabelen fsr
int fsrpin = 0;       // force sensitive resistor analoge pin 0 -> met 10K resistor
int fsrwaarde;        // een variabele voor het uitlezen van de fsr waarde

//variabelen DC motor
int motorpin1 = 13;
int motorpin2 = 12;
int ena = 11;

//varianelen knop
int knoppin = 3;
int knop;

int waarde = LOW;


void setup() {
  Serial.begin(9600);
  
  pinMode(fsrpin, INPUT);

  pinMode(motorpin1, OUTPUT);
  pinMode(motorpin2, OUTPUT);
  pinMode(ena, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(knoppin, INPUT);

  digitalWrite(motorpin1, LOW);       //de motor afleggen
  digitalWrite(motorpin2, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  analogWrite(ena, 100);               //de snelheid van de motor bepalen (0 = af en 255 = max snelheid)



}

void blink(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}

void loop() {
  fsrwaarde = analogRead(fsrpin);         //de fsr waarde constant aflezen en opslaan
  knop = digitalRead(knoppin);            //de knopwaarde van de knoppin aflezen



  Serial.println("Duw nu op de knop om het testscript te starten");

  if (knop == HIGH){
    Serial.println("Testscript start nu, er werd op de knop geduwd, duw niet meer op de knop tot na het einde van het script.");

    Serial.println("Motor gaat nu aan.");
    digitalWrite(motorpin1, HIGH);
    delay(5000);
    Serial.println("motor gaat nu uit.");
    digitalWrite(motorpin1, LOW);

    Serial.println("blijf nu op de force sensitive resistor duwen tot het lichtje aangaat");
    delay(2000);

    if (fsrwaarde > 15){
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("Er wordt op de fsr geduwd");
    }

    if (fsrwaarde < 15){
      digitalWrite(LED_BUILTIN, LOW);
    }


    

  }




}










