# flightsimulator

The program allows you to simulate the flight of planes. The simulation ends when the plane lands at the airport (0,0). The plane always asks the tower if it can change position. At startup, the program asks how many planes to create.

## output

```
it120 n56 m17974 o17974 t1872.48ms
it121 n74 m18232 o18232 t1874.12ms
it122 n39 m18322 o18322 t1874.75ms
it123 n9 m18657 o18659 t1875.95ms
```
-```it``` the smaller number, the earlier the plane landed,
-```n``` the smaller number, the earlier the plane was created,
-```m``` movements,
-```o``` movements + waiting when a collision has occurred,
-```t``` time from creating to landing in ms.