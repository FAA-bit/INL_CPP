# INL1
Dokumentation: Mätvärdesprogram i C++
Översikt:
Detta program låter användaren mata in upp till 25 mätvärden och utföra grundläggande statistisk analys. Det erbjuder en menybaserad struktur för att:
- Mata in nya värden
- Visa statistik (medelvärde, varians, summa etc.)
- Sortera värden
- Söka efter specifika värden 

Variabler:
- MAX: Max antal mätvärden som får matas in.
- mätvärden: Array som lagrar mätvärden.
- antal: Räknar hur många värden som har matats in. Funktioner:

MeasureInValues() - Syfte med detta är låter användaren mata in mätvärden tills hen skriver 'f' eller når maxgränsen, den accepterar decimaltal också hanterar felaktig inmatning med cin.fail().

showStatistics()  - Dess syfte är att beräkna och visa statistik baserat på inmatade värden.
Utskrift:
- Antal värden
- Summa
- Medelvärde
- Min- och maxvärde
- Varians
- Standardavvikelse
sortValues()  - Syftet är att sortera mätvärdena i stigande ordning med hjälp av en enkel bubbelsorteringsalgoritm.
Skriv ut:
- Visar sorterade värden rad för rad.
- Bekräftar att sorteringen är klar.

searchValue()  - Syfte är att söka efter ett specifikt värde som användaren anger.
den visar alla positioner där värdet hittas också meddelar om värdet inte finns.

simulateSensor() - Syfte är att låter programmet automatiskt generera ett antal slumpmässiga mätvärden, som om de kom från en verklig sensor (t.ex. temperaturer mellan 20–30 °C). Dessa värden används sedan för statistisk analys precis som manuellt inmatade värden. 
