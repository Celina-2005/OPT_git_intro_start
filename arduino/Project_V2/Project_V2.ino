/*
Versie 2 code project opkomende technologiën
24/04/2026
door Axelle De Bleser & Selena Rootsaert

*/

//variabelen fsr
int fsrpin = 0;       // force sensitive resistor ANALOGE pin 0 -> met 10K resistor
int fsrwaarde;        // een variabele voor het uitlezen van de fsr waarde

//variabelen DC motor
int motorpin1 = 13;
int motorpin2 = 12;
int ena = 11;

//varianelen knop
int knoppin = 3;
int knop;
int knopteller = 1;


void setup() {
  Serial.begin(9600);
  
  pinMode(fsrpin, INPUT);

  pinMode(motorpin1, OUTPUT);
  pinMode(motorpin2, OUTPUT);
  pinMode(ena, OUTPUT);

  pinMode(knoppin, INPUT);

  digitalWrite(motorpin1, LOW);       //de motor afleggen
  digitalWrite(motorpin2, LOW);
  analogWrite(ena, 100);               //de snelheid van de motor bepalen (0 = af en 255 = max snelheid)


}

void ademhulp() {                         //motor aanleggen en tonen op Seriële monitor
  digitalWrite(motorpin1, HIGH);
 // Serial.println("AAN");
}

void ademhulp_uit() {                     // motor uitzetten en tonen op Seriële monitor
  digitalWrite(motorpin1, LOW);
 // Serial.println("UIT");
}

void loop() {
  fsrwaarde = analogRead(fsrpin);         //de fsr waarde constant aflezen en opslaan
//  Serial.print("waarde fsr = ");          //fsr waarde ter controle printen in seriële monitor
  Serial.println(fsrwaarde);
  delay(100);

  knop = digitalRead(knoppin);            //de knopwaarde van de knoppin aflezen
  Serial.println(knopteller);


  if (knop == HIGH){                      // als de knop ingeduwd wordt de knopteller even maken
    knopteller += 1;
    delay(500);
  }

  if (((knopteller % 2) == 0) && (fsrwaarde > 15)){             //als de knopteller even is ademhulp aanleggen en de knopteller terug oneven maken
    ademhulp();
    knopteller += 1;
  }

  if (((knopteller % 2) != 0) && (!(fsrwaarde > 15))){       //als de knopteller oneven is en de fsr wordt niet meer aangeraakt de ademhulp afleggen
    ademhulp_uit();
  } 


 if (fsrwaarde < 50){                                //als de fsr niet aangeraakt wordt, "neutraal" doorsturen voor de app
  Serial.println("NEUTRAL");
 }

 if (fsrwaarde > 400){                              // als de fsr te hard aangeraakt wordt, "sad" doorsturen voor de app
  Serial.println("SAD");
 }

 if ((50 < fsrwaarde) && (fsrwaarde < 400)){        //als de fsr normaal aangeraakt wordt, "happy" doorsturen voor de app
  Serial.println("HAPPY");
 }




}










