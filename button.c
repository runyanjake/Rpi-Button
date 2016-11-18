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
#define DELAY_TIME_MS 1000

//**** Define Enums ****
enum{
	STARTUP,
	MODE1,
	MODE2,
	MODE3,
	SHUTDOWN
	} state = STARTUP;

//**** Function Declarations ****
int lightShowBlink();

int main(){
	int continue = 1;
	while(continue){
		switch (state){
			case STARTUP:
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
				state = MODE1;
			case MODE1:
				printf("IN MODE 1\n");
				if(lightShowBlink() == 1){
					state = MODE2;
				}
				break;
			case MODE2:
				if(1 == 1){
					state = MODE3;
				}
				break;
			case MODE3:
				if(1 == 1){
					state = SHUTDOWN;
				}
				break;
			case SHUTDOWN:
				digitalWrite(LED_1, LOW);
		                digitalWrite(LED_2, LOW);
	         	        digitalWrite(LED_3, LOW);
	         	        digitalWrite(LED_4, LOW);
	         	        digitalWrite(LED_5, LOW);
	         	        digitalWrite(LED_6, LOW);
	         	        digitalWrite(LED_7, LOW);
	         	        digitalWrite(LED_8, LOW);
				digitalWrite(BUT_IN, 0);
				continue = 0; //ends program
		}
	}
	return 1;
}

//Blink Loop
int lightShowBlink(){
	int ctrl = 0;
	for(ctrl=0;ctrl<10;ctrl++){
		//check for button press often enough so that it's responsive
		if(digitalRead(BUT_OUT))return 1;

		digitalWrite(LED_1, HIGH);
		digitalWrite(LED_2, HIGH);
		digitalWrite(LED_3, HIGH);
		digitalWrite(LED_4, HIGH);
		digitalWrite(LED_5, HIGH);
		digitalWrite(LED_6, HIGH);
		digitalWrite(LED_7, HIGH);
		digitalWrite(LED_8, HIGH);
		printf("Button: %d\n", digitalRead(BUT_OUT));

		delay(DELAY_TIME_MS);

		//check for button press often enough so that it's responsive
                if(digitalRead(BUT_OUT))return 1;

		digitalWrite(LED_1, LOW);
		digitalWrite(LED_2, LOW);
		digitalWrite(LED_3, LOW);
		digitalWrite(LED_4, LOW);
		digitalWrite(LED_5, LOW);
		digitalWrite(LED_6, LOW);
		digitalWrite(LED_7, LOW);
		digitalWrite(LED_8, LOW);
		printf("Button: %d\n", digitalRead(BUT_OUT));

		delay(DELAY_TIME_MS);
	}
	return 0;
}


