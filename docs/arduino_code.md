# Arduino Code Documentatie

**Auteur(s) :**
- De Bleser, Axelle; Rootsaert, Selena

## 1. Inleiding
Initieel werden alle onderdelen individueel getest. Dit werd gedaan door een kleine code te schrijven om de waarde uit te lezen en te printen op de seriële monitor. 

Nadat alle codes van de onderdelen duidelijk waren werd de volledige code van het project geschreven.
Deze code is hieronder te vinden.


<details>
<summary>Volledige code</summary>

```cpp
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
  Serial.print("VALUE||");
  Serial.println(fsrwaarde);
  delay(100);

  knop = digitalRead(knoppin);            //de knopwaarde van de knoppin aflezen


  if (knop == HIGH){                      // als de knop ingeduwd wordt de knopteller even maken
    knopteller += 1;
    delay(500);
  }

  if ((knopteller % 2) == 0){             //als de knopteller even is ademhulp aanleggen en de knopteller terug oneven maken
    ademhulp();
    knopteller += 1;
  }

  if (((knopteller % 2) != 0) && (!(fsrwaarde > 15))){       //als de knopteller oneven is en de fsr wordt niet meer aangeraakt de ademhulp afleggen
    ademhulp_uit();
  } 


 if (fsrwaarde < 50){
  Serial.println("NEUTRAL");
 }

 if (fsrwaarde > 400){
  Serial.println("SAD");
 }

 if ((50 < fsrwaarde) && (fsrwaarde < 400)){
  Serial.println("HAPPY");
 }


}

```

</details>

## 2. Variabelen en Pinconfiguratie
```cpp
// variabelen fsr
int fsrpin = 0;
int fsrwaarde;

// variabelen DC motor
int motorpin1 = 13;
int motorpin2 = 12;
int ena = 11;

// variabelen knop
int knoppin = 3;
int knop;
int knopteller = 1;

```

In dit deel worden alle variabelen en pinnen gedefinieerd.
- De FSR-sensor gebruikt analoge pin A0.
- De DC-motor gebruikt twee richtingspinnen en één PWM-pin voor snelheidsregeling.
- De drukknop wordt gebruikt om de ademhulp aan of uit te schakelen.


## 3. Setup-functie
```cpp
void setup() {
  Serial.begin(9600);

  pinMode(fsrpin, INPUT);

  pinMode(motorpin1, OUTPUT);
  pinMode(motorpin2, OUTPUT);
  pinMode(ena, OUTPUT);

  pinMode(knoppin, INPUT);

  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, LOW);

  analogWrite(ena, 100);
}

```
De ``setup()``-functie wordt één keer uitgevoerd bij het opstarten van de Arduino.

Hier worden :
- de seriële communicatie gestart;
- alle pinnen ingesteld als input of output;
- de motor standaard uitgeschakeld;
- de motorsnelheid ingesteld via PWM.


## 4. Functie: Ademhulp inschakelen
```cpp
void ademhulp() {
  digitalWrite(motorpin1, HIGH);
}
```
Deze functie schakelt de motor in.
Wanneer de functie wordt aangeroepen, start de ademhulp.


## 5. Functie: Ademhulp uitschakelen
```cpp
void ademhulp_uit() {
  digitalWrite(motorpin1, LOW);
}
```
Deze functie schakelt de motor uit.
De ademhulp stopt wanneer de sensor geen druk meer detecteert.

## 6. Uitlezen van de FSR-sensor
```cpp
fsrwaarde = analogRead(fsrpin);

Serial.print("VALUE||");
Serial.println(fsrwaarde);

delay(100);
```

De Arduino leest continu de waarde van de FSR-sensor uit.
Deze waarde wordt doorgestuurd naar de seriële monitor voor controle en verwerking.



## 7. Drukknop uitlezen
```cpp
knop = digitalRead(knoppin);

if (knop == HIGH) {
  knopteller += 1;
  delay(500);
}
```
Wanneer de knop wordt ingedrukt, verhoogt de teller met één.
De vertraging (``delay``) voorkomt dat één druk meerdere keren geregistreerd wordt.


## 8. Ademhulp activeren
```cpp
if ((knopteller % 2) == 0) {
  ademhulp();
  knopteller += 1;
}
```
Wanneer de teller een even waarde heeft, wordt de ademhulp ingeschakeld.
Hierdoor werkt de knop als een eenvoudige aan/uit-schakelaar.


## 9. Ademhulp uitschakelen bij geen druk
```cpp
if (((knopteller % 2) != 0) && (!(fsrwaarde > 15))) {
  ademhulp_uit();
}
```
Als er geen druk meer wordt gemeten op de FSR-sensor, schakelt de motor automatisch uit.
Dit zorgt ervoor dat de ademhulp enkel actief blijft tijdens gebruik.

## 10. Detectie van emoties/statussen
```cpp
if (fsrwaarde < 50){
  Serial.println("NEUTRAL");
}

if (fsrwaarde > 400){
  Serial.println("SAD");
}

if ((50 < fsrwaarde) && (fsrwaarde < 400)){
  Serial.println("HAPPY");
}
```
Op basis van de drukwaarde van de sensor wordt een status bepaald :
- NEUTRAL bij lage druk;
- HAPPY bij gemiddelde druk;
- SAD bij hoge druk.

Deze waarden worden weergegeven in de seriële monitor en kunnen gebruikt worden voor verdere verwerking in het project.



---

## 11. Conclusie

De code combineert verschillende componenten in één systeem: een FSR-druksensor, een drukknop en een DC-motor.

De sensor meet de druk, terwijl de knop gebruikt wordt om de ademhulp te activeren. Op basis van de gemeten waarden worden verschillende statussen weergegeven via de seriële monitor. Hierdoor ontstaat een eenvoudige maar functionele interactie tussen gebruiker en systeem.

<p align="center">
  <img src="../imgs/functieschema.png"width="750">
  <br>
  Figuur 1. functieschema
</p>

In dit functieschema is de volledige werking van de code weergegeven.