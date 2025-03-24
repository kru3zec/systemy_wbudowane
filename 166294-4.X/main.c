/* 
 * File:   main.c
 * Author: local
 *
 * Created on 14 maja 2024, 15:28
 */

#include <xc.h>
#include <libpic30.h>
#include <stdio.h>
#include <string.h>
#include "lcd.h"
#include "buttons.h"
#include "adc.h"
#define TOTAL_TIME (300) // w sekundach
volatile unsigned int seconds = TOTAL_TIME;
int main(void) {
    ADC_SetConfiguration(ADC_CONFIGURATION_DEFAULT);
 // ADC ma czyta? potencjometr
 ADC_ChannelEnable(ADC_CHANNEL_POTENTIOMETER);
unsigned int suwak;
    TRISA = 0x0000;
    char buffer[16]; // bufor na znaki do wy?wietlenia na ekranie
    LCD_Initialize(); // inicjalizacja LCD
    unsigned int remainingSeconds = seconds;
    int flaga = 0;
while(remainingSeconds > 1) {
    suwak = ADC_Read10bit(ADC_CHANNEL_POTENTIOMETER);
    unsigned char normalizedValue = suwak >> 2;

    if (BUTTON_IsPressed ( BUTTON_S3 ) == true) {
        remainingSeconds = remainingSeconds + 30;
    } else if ((BUTTON_IsPressed ( BUTTON_S4 ) == true)) {
        remainingSeconds = remainingSeconds - 30;
    } else if ((BUTTON_IsPressed ( BUTTON_S5 ) == true)) {
        if(flaga == 0){
            flaga = 1;
        }
        else{
            flaga = 0;
        }
    } else if ((BUTTON_IsPressed ( BUTTON_S6 ) == true)) {
        flaga = 0;
        remainingSeconds = seconds;
    }
    if(flaga == 1){
        remainingSeconds--;
    }
    double procent =  (normalizedValue/255.0)*100.0;
    unsigned char minutes = remainingSeconds / 60;
    unsigned char secs = remainingSeconds % 60;
    sprintf(buffer, "Czas: %02u:%02u %03u", minutes, secs,(int) procent); // zapis czasu do bufora
// wy?wietlenie na ekranie
    LCD_ClearScreen();
    LCD_PutString(buffer, strlen(buffer));
    __delay32(4000000); //czekamy sekund?
 
}
    sprintf(buffer, "%12s", "koniec czasu");
    LCD_ClearScreen();
    LCD_PutString(buffer, strlen(buffer));
    __delay32(40000000); //czekamy 10 sekund
return 0;
}
