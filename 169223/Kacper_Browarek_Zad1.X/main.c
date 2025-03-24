/* 
 * File:   main.c
 * Author: local
 *
 * Created on March 24, 2025, 8:46 AM
 */
#include <xc.h>
#include "p24FJ128GA010.h"



/*
 * 
 */
#define Fos 8000000
#define PreScalar 256
#define TperS Fos / 2 / PreScalar
void setTimer(){
    TMR1 = 0;
    PR1 = 0xFFFF;
    T1CON = 0x8030;
    
}


int main(void) {
    int TRISA = 0;
    int LATA = 0;
    setTimer();
    while(1){
        uint16_t i;
        for(i = 0;i < 80000;i++ ){
            
        }
        TMR1 = 0;
        LATA = ~LATA
                
    }

    return (0);
}

// Program diod 
