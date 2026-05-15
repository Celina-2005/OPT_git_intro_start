# Algemene werking
In dit bestand wordt uitgelegd hoe het project algemeen te werk gaat.

**Auteur(s) :**
- De Bleser, Axelle; Rootsaert, Selena

Binnen dit project werd voornamelijk gewerkt op:
- de visuele interface van Wobble,
- de integratie van een motorisch component,
- communicatie tussen Arduino en Protopie.

Het systeem werkt op basis van een druksensor (FSR). Wanneer een gebruiker Wobble aanraakt, leest Arduino een drukwaarde uit. Deze waarde wordt vervolgens doorgestuurd naar Protopie Connect, waarna de interface op een extern scherm (gsm) reageert.

De interface verandert afhankelijk van de hoeveelheid druk:
- geen contact → gele achtergrond + neutraal gezicht,
- lichte aanraking (zoals aaien of knuffelen) → groene achtergrond + blij gezicht,
- harde aanraking → rode achtergrond + boos/verdrietig gezicht.

Hierdoor ontstaat een directe koppeling tussen fysieke interactie en visuele feedback.

<p align="center">
  <img src="../imgs/Flowchart.png" width="750">
  <br>
  Figuur 1. Flowchart
</p>

Daarnaast werd ook een motorisch component toegevoegd. Een drukknop bepaalt of Wobble actief staat. De motor wordt enkel geactiveerd wanneer:
1. Wobble aanstaat via de drukknop,
2. er aanraking wordt gedetecteerd via de druksensor.

Zo wordt vermeden dat de motor constant actief blijft.




## Diagram
![alt text](../imgs/Diagram.png)