# Algemene werking
In dit bestand wordt uitgelegd hoe het project algemeen te werk gaat.



Binnen dit project werd voornamelijk gewerkt op :
- de visuele interface van Wobble,
- de integratie van een motorisch component,
- communicatie tussen Arduino en Protopie.

Het systeem werkt op basis van een druksensor (FSR). Wanneer een gebruiker Wobble aanraakt, leest Arduino een drukwaarde uit. Deze waarde wordt vervolgens doorgestuurd naar Protopie Connect, waarna de interface op een extern scherm (gsm) reageert.

De interface verandert afhankelijk van de hoeveelheid druk :
- geen contact → gele achtergrond + neutraal gezicht,
- lichte aanraking (zoals aaien of knuffelen) → groene achtergrond + blij gezicht,
- harde aanraking → rode achtergrond + boos/verdrietig gezicht.

Hierdoor ontstaat een directe koppeling tussen fysieke interactie en visuele feedback.

```mermaid

flowchart LR
    B["Arduino leest drukwaarde uit"] -- Seriële communicatie --> C["Protopie Connect"]
    C -- Update interface --> J{"Drukwaarde"}
    E["Drukknop ingedrukt"] -- Ja --> G{"Gebruiker raakt Wobble aan? (druksensor)"}
    G -- Ja --> H["Motor geactiveerd"]
    H -- combinatie --> B
    G -- Nee --> I["Motor uit"]
    E -- Nee --> I
    J -- Geen contact --> K["Gele achtergrond + neutraal gezicht"]
    J -- Lichte aanraking --> L["Groene achtergrond + blij gezicht"]
    J -- Harde aanraking --> M["Rode achtergrond + boos/verdrietig gezicht"]
    K --> D["Extern scherm"]
    L --> D
    M --> D

    style B fill:#ecfeff,stroke:#22d3ee
    style C fill:#f5f3ff,stroke:#a78bfa
    style J fill:#fef2f2,stroke:#f87171
    style E fill:#f0fdf4,stroke:#4ade80
    style G fill:#fef2f2,stroke:#f87171
    style H fill:#fdf4ff,stroke:#e879f9
    style I fill:#eef2ff,stroke:#818cf8
    style K fill:#fefce8,stroke:#facc15
    style L fill:#f0fdf4,stroke:#4ade80
    style M fill:#fef2f2,stroke:#f87171
    style D fill:#fff7ed,stroke:#fb923c

```


<p align="center">
    Figuur 1. Flowchart
</p>

Daarnaast werd ook een motorisch component toegevoegd. Een drukknop bepaalt of Wobble actief staat. De motor wordt enkel geactiveerd wanneer :
1. Wobble aanstaat via de drukknop,
2. Er aanraking wordt gedetecteerd via de druksensor.

Zo wordt vermeden dat de motor constant actief blijft.




## Originele Diagram
<p align="center">
<img src="../imgs/Diagram.png" width="750">
Figuur 2. Originele diagram
</p>

Initieel was dit diagram ons eerste idee voor het project. Wegens de vele bedrading bij de matrix werd het scherm vervangen door het scherm met protopie. Er werd bovenop de gezichtsuitdrukkingen ook een kleurenovergang gemaakt om de feedback visueler voor te stellen.
Omdat de figma app voor project gebruiksgericht volledig overbodig was hadden we ons meer gefocust op het scherm met protopie en hadden we besloten het scherm weg te laten.