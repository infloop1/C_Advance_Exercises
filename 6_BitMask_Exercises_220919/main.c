#include <stdio.h>
#include <stdint.h>
#include <time.h> // delay

typedef enum{
    GPIO_PIN_0 = 1,
    GPIO_PIN_1 = 1 << 1,
    GPIO_PIN_2 = 1 << 2,
    GPIO_PIN_3 = 1 << 3,
    GPIO_PIN_4 = 1 << 4,
    GPIO_PIN_5 = 1 << 5,
    GPIO_PIN_6 = 1 << 6,
    GPIO_PIN_7 = 1 << 7
}GPIO_PIN;

typedef enum{
    LOW = 0,
    HIGH
}STATUS;

uint8_t PORTA = 0b00000000;

void digitalWrite( GPIO_PIN PIN, STATUS stt);
void delay(int number_of_seconds);
void blinkLed(GPIO_PIN PIN, int time_delay );


int main(int argc, char const *argv[])
{
    // Test digitalWrite
    digitalWrite(GPIO_PIN_6, HIGH);
    printf("Trang thai Port 6: %d\n", PORTA);
    digitalWrite(GPIO_PIN_6, LOW);
    printf("Trang thai Port 6: %d\n", PORTA);
    while(1){
        // Test blinkLed: Nhap nhay Port5 moi lan 1 giay
        blinkLed(GPIO_PIN_5, 1);
    }
    return 0;
}

void digitalWrite( GPIO_PIN PIN, STATUS stt){
    if(stt)  PORTA |= PIN;
    else PORTA ^= PIN; //XOR
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
    // Storing start time
    clock_t start_time = clock();
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void blinkLed(GPIO_PIN PIN, int time_delay ){
    PORTA ^= PIN;
    printf("%d\n", PORTA);
    delay(time_delay);
}