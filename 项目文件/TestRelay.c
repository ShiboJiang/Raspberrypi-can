/*-----------------------------------------------------------------------------
 Function   : Used for testing RaspberryPi ZeroW's gpio pin -> Relay 
 FileName   : TestRelay.c
 Author     : Tomato
 Time       : 2019.2.4
 Version    : 0.1
 Notes      : None
-----------------------------------------------------------------------------*/
#include <wiringPi.h>
#include <softPwm.h>

/* Macro config define */
#define RELAY_1   20U
#define RELAY_2   21U
#define PWM_1     26U

/* Parameter define */
static int high_edge_time = 0;   // uint :0.1ms
static int cycle_time     = 200; // uint :0.1ms

int main (void)
{
    /* Initial gpio with chip pin ,if use mapping pin -> wiringPiSetup*/
    wiringPiSetupGpio () ;
    /* Set relay1&2 pwm pin as output */
    pinMode (RELAY_1, OUTPUT) ;  /* INPUT
                                    OUTPUT
                                    PWM_OUTPUT
                                    GPIO_CLOCK
                                    SOFT_PWM_OUTPUT
                                    SOFT_TONE_OUTPUT
                                    PWM_TONE_OUTPUT */
    pinMode (RELAY_2, OUTPUT) ;
    pinMode (PWM_1, SOFT_PWM_OUTPUT) ;
    softPwmCreate(PWM_1,high_edge_time,cycle_time);

    /* Main loop function */
    for (;;)
    {
        /* Control relay */
        digitalWrite (RELAY_1, HIGH) ; 
        delay (500) ;
        digitalWrite (RELAY_1,  LOW) ; 
        delay (500) ;

        /* Control pwm */
        softPwmWrite(PWM_1, 20); // duty = 20/cycle_time
        delay (5000);
        softPwmWrite(PWM_1, 50);
        delay (5000);
        softPwmWrite(PWM_1, 90);
        delay (5000);
    }
    return 0 ;
}