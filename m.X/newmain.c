// PIC24FJ128GA010 Configuration Bit Settings
// For more on Configuration Bits, see Section 1.1
// consult your device data sheet
// CONFIG2
#pragma config POSCMOD = XT // XT Oscillator mode selected
#pragma config OSCIOFNC = ON // OSC2/CLKO/RC15 as port I/O (RC15)
#pragma config FCKSM = CSDCMD // Clock Switching and Monitor disabled
#pragma config FNOSC = PRI // Primary Oscillator (XT, HS, EC)
#pragma config IESO = ON // Int Ext Switch Over Mode enabled
// CONFIG1
#pragma config WDTPS = PS32768 // Watchdog Timer Postscaler (1:32,768)
#pragma config FWPSA = PR128 // WDT Prescaler (1:128)
#pragma config WINDIS = ON // Watchdog Timer Window Mode disabled
#pragma config FWDTEN = OFF // Watchdog Timer disabled
#pragma config ICS = PGx2 // Emulator/debugger uses EMUC2/EMUD2
#pragma config GWRP = OFF // Writes to program memory allowed
#pragma config GCP = OFF // Code protection is disabled
#pragma config JTAGEN = OFF // JTAG port is disabled
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
#include <xc.h>
#include <libpic30.h>
#include "buttons.h"

// Tablica rejestrów przesuwaj?cych
unsigned char rejestry[6] = { 1, 1, 1, 0, 0, 1 };

// Funkcja generuj?ca jedn? 6-bitow? liczb? pseudolosow?
unsigned char generujLiczbe() {
  // Obliczenie nowej warto?ci bitu 0
  unsigned char nowyBit0 = rejestry[0] ^ rejestry[2] ^ rejestry[5];

  // Przesuni?cie bitów w rejestrach
  for (int i = 5; i > 0; i--) {
    rejestry[i] = rejestry[i - 1];
  }

  // Ustawienie nowego bitu 0
  rejestry[0] = nowyBit0;

  // Z?o?enie 6-bitowej liczby pseudolosowej z rejestrów
  unsigned char liczbaPseudolosowa = 0;
  for (int i = 0; i < 6; i++) {
    liczbaPseudolosowa |= (rejestry[i] << (5 - i));
  }

  return liczbaPseudolosowa;
}

int main(void) {
unsigned char portValue;
const unsigned char BCD_table[256] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29,
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39,
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49,
    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59,
    0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69,
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79,
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89,
    0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9,
    0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9,
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9,
    0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9,
    0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9,
    0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9 
};
// Port A access
AD1PCFG = 0xFFFF;
TRISA = 0x0000;
int temp = 0;
portValue = 0b00000000;
int flag = 0;
int first = 1;
int flaga = 0;
int firsta = 0;;
 int start = 0b00000001;
    int n = 0b00000001;
    int temp_2 = 0b00000000;
    int z = 8;
while(1) {
    __delay32(1500000);
 if (BUTTON_IsPressed ( BUTTON_S3 ) == true) {
     temp++;
     LATA = temp;
     if(temp == 5){
          portValue = 0xFF;
     }
     else if(temp == 7){
         portValue = 0b00000111; 
     }
     else if(temp == 1){
         portValue = 0b11111111; 
     }
     else if(temp == 6){
         portValue = 0b00000111;
     }
     else{
        portValue = 0b00000000;
     }
     __delay32(3500000);

 } else if ((BUTTON_IsPressed ( BUTTON_S4 ) == true)) {
     temp--;
     LATA = temp;
     if(temp == 5){
          portValue = 0xFF;
     }
     else if(temp == 7){
         portValue = 0b00000111; 
     }
     else if(temp == 1){
         portValue = 0b11111111; 
     }
     else if(temp == 6){
         portValue = 0b00000111;
     }
     else{
        portValue = 0b00000000;
     }
     __delay32(3500000);

 }
 if(temp == 10){
     temp=0;
 }
    if(temp == -1){
        temp = 9;
    }
    if(temp == 0){
if(portValue == 0x255){
    portValue = 0x0;
    }
    portValue++;
LATA = portValue; // write to port latch
// delay value change
__delay32(1500000); // delay in instruction cycles
    }
 if(temp == 1){
if(portValue == 0b00000000){
    portValue = 0b11111111;
    }
    portValue--;
LATA = portValue; // write to port latch
// delay value change
__delay32(1500000); // delay in instruction cycles
    }
    if(temp == 2){
            if(portValue == 0b11111111){
      portValue = 0b00000000;
    }
    portValue++;


    unsigned char grayCode = portValue >> 7;
    for (int i = 6; i >= 0; i--) {
      grayCode <<= 1;
      grayCode |= ((portValue >> i) & 1) ^ ((portValue >> (i + 1)) & 1);
    }

    LATA = grayCode;


    __delay32(1500000);
    }
    if(temp == 3){
        if(portValue == 0b00000000){
      portValue = 0b11111111;
    }
    portValue--;


    unsigned char grayCode = portValue >> 7;
    for (int i = 6; i >= 0; i--) {
      grayCode <<= 1;
      grayCode |= ((portValue >> i) & 1) ^ ((portValue >> (i + 1)) & 1);
    }

    LATA = grayCode;


    __delay32(1500000);
    }
    if(temp == 4){
        if (portValue == 0xFF) {  // Sprawd?, czy osi?gni?to maksymaln? warto?? BCD (99)
            portValue = 0x00;     // Zresetuj warto?? portu
        } else {
            portValue++;          // Inkrementuj warto?? portu
        }

        // Konwersja binarna do BCD
        unsigned char upperDigit = (portValue >> 4) & 0x0F;  // Wyodr?bnij starsz? cyfr?
        unsigned char lowerDigit = portValue & 0x0F;       // Wyodr?bnij m?odsz? cyfr?

        // Wy?wietl warto?? BCD na porcie A (wymaga odpowiedniego sprz?tu)
        LATA = (BCD_table[upperDigit] << 4) | BCD_table[lowerDigit];

        __delay32(1500000); // Opó?nienie 1,5 sekundy
    }
    if(temp == 5){
if (portValue == 0x00) { // Sprawd?, czy osi?gni?to minimaln? warto?? BCD (0)
  portValue = 0x99; // Zresetuj warto?? portu
} else {
  portValue--; // Dekrementuj warto?? portu
}

// Konwersja binarna do BCD
unsigned char upperDigit = (portValue >> 4) & 0x0F; // Wyodr?bnij starsz? cyfr?
unsigned char lowerDigit = portValue & 0x0F; // Wyodr?bnij m?odsz? cyfr?

// Wy?wietl warto?? BCD na porcie A (wymaga odpowiedniego sprz?tu)
LATA = (BCD_table[upperDigit] << 4) | BCD_table[lowerDigit];

__delay32(1500000);
    }
    if(temp == 6){
        if(flag == 1){
    portValue >>= 1;
    }
    else{
        portValue <<= 1;
    }
    if(portValue == 0b1110000){
        flag = 1;
    }
    if(portValue == 0b0000111 & first >= 1){
        flag = 0;
    }
LATA = portValue; // write to port latch
// delay value change
__delay32(150000); // delay in instruction cycles
flag++;
    }
    if(temp == 7){
    if(flaga == 1){
            portValue >>= 1;
        } else{
            portValue <<= 1;
        }
LATA = portValue; // write to port latch
// delay value change
__delay32(1500000); // delay in instruction cycles
if(portValue == 0b11100000){
            flaga = 1;
        }
        if(firsta == 1 & portValue == 0b00000111){
            flaga = 0;
        }
        firsta = 1;
    }
    if(temp == 8){
        for(int i = 0;i<z;i++){
            portValue=temp_2+n;
            LATA = portValue;
            __delay32(15000);;
            if(i == (z-1)){
                temp_2 +=n;
            }
            else{
            n <<= 1;
            }
            }

        n=start;
        z--;
        __delay32(150000); 
        if(temp_2 == 0b11111111){
            start = 0b00000001;
            n = 0b00000001;
            temp_2 = 0b00000000;
        }
    }
        if(temp == 9){
            LATA = generujLiczbe();
            __delay32(1500000);
    }
}

return -1;
}
