// CONFIG2
#pragma config POSCMOD = HS      // Primary Oscillator Select (HS Oscillator mode selected)
#pragma config OSCIOFNC = OFF    // Primary Oscillator Output Function (OSC2/CLKO/RC15 functions as CLKO (FOSC/2))
#pragma config FCKSM = CSDCMD    // Clock Switching and Monitor (Clock switching and Fail-Safe Clock Monitor are disabled)
#pragma config FNOSC = PRIPLL    // Oscillator Select (Primary Oscillator with PLL module (HSPLL, ECPLL))
#pragma config IESO = OFF        // Internal External Switch Over Mode (IESO mode (Two-Speed Start-up) disabled)

// CONFIG1
#pragma config WDTPS = PS32768   // Watchdog Timer Postscaler (1:32,768)
#pragma config FWPSA = PR128     // WDT Prescaler (Prescaler ratio of 1:128)
#pragma config WINDIS = ON       // Watchdog Timer Window (Standard Watchdog Timer enabled, Windowed-mode is disabled)
#pragma config FWDTEN = OFF      // Watchdog Timer Enable (Watchdog Timer is disabled)
#pragma config ICS = PGx2        // Comm Channel Select (Emulator/debugger uses EMUC2/EMUD2)
#pragma config GWRP = OFF        // General Code Segment Write Protect (Writes to program memory are allowed)
#pragma config GCP = OFF         // General Code Segment Code Protect (Code protection is disabled)
#pragma config JTAGEN = OFF      // JTAG Port Enable (JTAG port is disabled)

#include <xc.h>
#include <libpic30.h>
#include <stdio.h>
#include <math.h>

// Makro do wyodrêbniania konkretnego bitu z warto?ci
#define GET_BIT(value, bit_position) ((value >> bit_position) & 1)

// Zmienne do przechowywania stanów przycisków
char buttonA = 0, buttonB = 0;


// FUNKCJE POMOCNICZE


// Funkcja do sprawdzania stanów przycisków i aktualizacji zadania
int update_task(int current_task) {
    buttonA = PORTDbits.RD6; // Odczyt stanu przycisku A
    buttonB = PORTDbits.RD7; // Odczyt stanu przycisku B
    __delay32(1500000); // Opó?nienie dla eliminacji drgañ styków

    // Zwiêksz zadanie je?li przycisk A jest wci?niêty
    if (buttonA == 1) {
        current_task++;
        if (current_task > 9) {
            current_task = 1; // Prze³¹cz na pierwsze zadanie po osi¹gniêciu 9
        }
    }

    // Zmniejsz zadanie je?li przycisk B jest wci?niêty
    if (buttonB == 1) {
        current_task--;
        if (current_task < 1) {
            current_task = 9; // Prze³¹cz na ostatnie zadanie je?li aktualne zadanie jest mniejsze ni¿ 1
        }
    }

    return current_task;
}

// Funkcja do konwersji liczby ca³kowitej na jej reprezentacjê w kodzie Graya
int int_to_gray(unsigned char number) {
    return (number >> 1) ^ number;
}

// Funkcja do generowania pseudolosowego bitu
unsigned int pseudo_random_bit(int seed) {
    return GET_BIT(seed, 0) ^ GET_BIT(seed, 1) ^ GET_BIT(seed, 4) ^ GET_BIT(seed, 5);
}

int main(void) {
    // Ustawienie portu A na wyj?cie i portu D na wej?cie
    TRISA = 0x0000;
    TRISD = 0xFFFF;

    unsigned led_output = 0x0000;
    int task_id = 1; // Pocz¹tkowe zadanie

    while (1) {
        LATA = led_output; // Ustawienie wyj?cia LED

        while (task_id == 1) { // Zadanie 1: inkrementacja wyj?cia LED
            led_output++;
            LATA = led_output;
            __delay32(1500000);
            task_id = update_task(task_id); // Aktualizacja zadania
        }
        led_output = 0x0000; // Zerowanie wyj?cia LED

        while (task_id == 2) { // Zadanie 2: dekrementacja wyj?cia LED
            led_output--;
            LATA = led_output;
            __delay32(1500000);
            task_id = update_task(task_id);
        }
        led_output = 0x0000;

        while (task_id == 3) { // Zadanie 3: inkrementacja kodu Graya
            for (int i = 0; i <= 255; i++) {
                LATA = int_to_gray(i);
                __delay32(1500000);
                task_id = update_task(task_id);
                if (task_id != 3) {
                    break;
                }
            }
        }
        led_output = 0x0000;

        while (task_id == 4) { // Zadanie 4: dekrementacja kodu Graya
            for (int i = 255; i >= 0; i--) {
                LATA = int_to_gray(i);
                __delay32(1500000);
                task_id = update_task(task_id);
                if (task_id != 4) {
                    break;
                }
            }
        }
        led_output = 0x0000;

        while (task_id == 5) { // Zadanie 5: inkrementacja wy?wietlania BCD
            for (int tens = 0; tens <= 9; tens++) {
                for (int units = 0; units <= 9; units++) {
                    LATA = 16 * tens + units;
                    __delay32(1500000);
                    task_id = update_task(task_id);
                    if (task_id != 5) {
                        break;
                    }
                }
            }
        }
        led_output = 0x0000;

        while (task_id == 6) { // Zadanie 6: dekrementacja wy?wietlania BCD
            for (int tens = 9; tens >= 0; tens--) {
                for (int units = 9; units >= 0; units--) {
                    LATA = 16 * tens + units;
                    __delay32(1500000);
                    task_id = update_task(task_id);
                    if (task_id != 6) {
                        break;
                    }
                }
            }
        }

        led_output = 0x0000;

        while (task_id == 7) {
            int snake_body = 0;
            int direction = 1; // 1: prawo, 0: lewo

            while (task_id == 7) {
                LATA = 7 << snake_body; // ustawienie 3-bitowego wê¿yka
                snake_body += direction; // zmiana pozycji wê¿yka
                if (snake_body == 0) {
                    direction = 1; // zmiana kierunku na prawo, je?li osi¹gnie lewy koniec
                } else if (snake_body >= 5) {
                    direction = -1; // zmiana kierunku na lewo, je?li osi¹gnie prawy koniec
                }
                __delay32(1500000); // opó?nienie
                task_id = update_task(task_id); // sprawdzenie przycisku
            }
        }

        led_output = 0x0000; // resetowanie led_output

        while (task_id == 8) {
            int zmiana = 0;

            while (task_id == 8) {
                zmiana = 0;
                for (int i = 7; i > 1; i -= 1) {
                    int a = GET_BIT(led_output, i); // warto?æ bitu na pozycji i
                    int b = GET_BIT(led_output, i - 1); // warto?æ bitu na pozycji i-1
                    if (a == 0 && b == 1) {
                        led_output += 1 << i; // przesuniêcie bitu na pozycji i
                        led_output -= 1 << i - 1; // wyzerowanie bitu na pozycji i-1
                        zmiana = 1; // flaga zmiany
                        break;
                    }
                }
                if (zmiana == 0) {
                    led_output += 1; // inkrementacja led_output, je?li nie by³o zmiany
                }
                if (led_output > 255) {
                    led_output = 0; // resetowanie led_output, je?li przekroczy 255
                }

                LATA = led_output; // ustawienie led_output na LATA
                __delay32(1500000); // opó?nienie
                task_id = update_task(task_id); // aktualizacja zadania
            }
        }

        led_output = 0x0000; // resetowanie led_output

        while (task_id == 9) {
            int seed = 1;
            while (task_id == 9) {
                int random_bit = pseudo_random_bit(seed);
                seed = (seed >> 1) | (random_bit << 5);
                __delay32(1500000);
                LATA = seed;
                task_id = update_task(task_id);
            }
        }
        led_output = 0x0000;
    }
    return 0;
}