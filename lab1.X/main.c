/* 
 * File:   main.c
 * Author: local
 *
 * Created on March 24, 2025, 10:36 AM
 */

#include "p24FJ128GA010.h"


int main(int argc, char** argv) {

    TRISA = 0;
    LATA = 0;
    
    while(1)
    {
        LATA = 0xFFFF;
    }
    
    
    return 0;
}

