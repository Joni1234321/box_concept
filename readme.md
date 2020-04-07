# box_concept

Dette er en række projekter der skal bruges som skabelon for mit BOX projekt

Målet er at lave følgende projekter:


**PIC->Display**

PIC controller der kan vise noget på et LCD display


**PIC->I2C->PIC->Display**

PIC controller der kan sende I2C signal til en PIC controller der kan vise noget på et LCD display


**PC->USB->PIC**

PIC controller der kan modtage og sende data gennem en UART port forbundet med computeren


**PC->USB->PIC->I2C->PIC->Display**

PC skal kunne sende et signal gennem en interface til en PIC controller der sender det videre til en anden controller der visualisere dataen
