#include "./wiringPi/wiringPi.h"
#include <stdio.h>

//**** Macro Define ****
#define LED_1 18
#define LED_2 23
#define LED_3 24
#define LED_4 25
#define LED_5 12
#define LED_6 16
#define LED_7 20
#define LED_8 21
#define BUT_IN 26
#define BUT_OUT 19

int main(){
	//Setup
	wiringPiSetupGpio();
	pinMode(LED_1, OUTPUT);
	pinMode(LED_2, OUTPUT);
	pinMode(LED_3, OUTPUT);
	pinMode(LED_4, OUTPUT);
	pinMode(LED_5, OUTPUT);
	pinMode(LED_6, OUTPUT);
	pinMode(LED_7, OUTPUT);
	pinMode(LED_8, OUTPUT);
	pinMode(BUT_OUT, INPUT);
	pinMode(BUT_IN, OUTPUT);

	//Pin 19 (Button input) always constant
	digitalWrite(BUT_IN, 1);

	//Loop
	int ctrl = 0;
	for(ctrl=0;ctrl<10;ctrl++){
		digitalWrite(LED_1, HIGH);
		digitalWrite(LED_2, HIGH);
		digitalWrite(LED_3, HIGH);
		digitalWrite(LED_4, HIGH);
		digitalWrite(LED_5, HIGH);
		digitalWrite(LED_6, HIGH);
		digitalWrite(LED_7, HIGH);
		digitalWrite(LED_8, HIGH);
		printf("Button: %d\n", digitalRead(BUT_OUT));

		delay(1000);

		digitalWrite(LED_1, LOW);
		digitalWrite(LED_2, LOW);
		digitalWrite(LED_3, LOW);
		digitalWrite(LED_4, LOW);
		digitalWrite(LED_5, LOW);
		digitalWrite(LED_6, LOW);
		digitalWrite(LED_7, LOW);
		digitalWrite(LED_8, LOW);
		printf("Button: %d\n", digitalRead(BUT_OUT));

		delay(1000);
	}

	//End Cleanup
	digitalWrite(BUT_IN, 0);
	return 1;
}

