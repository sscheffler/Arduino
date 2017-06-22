#include <avr/wdt.h>
#include <avr/sleep.h>
#include <avr/power.h>
 
#define LED 13
/**
 * see: https://playground.boxtec.ch/doku.php/arduino/sleep
 */
void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  prepareTimer();
}
 
void loop() {
  digitalWrite(LED, (bitRead(PORTB,5) ^ 1));
  Serial.println("Leg mich mal hin..");
  delay(80);
  sleep(5);
  Serial.println("Bin wieder da..");
}

void prepareTimer() {
  MCUSR &= ~(1<<WDRF);
  WDTCSR |= (1<<WDCE) | (1<<WDE);
  WDTCSR =  WDTO_1S;
  WDTCSR |= 1<<WDIE;
}

void sleep(int seconds){
  for (int i = 0; i < seconds; i ++){
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    power_adc_disable();
    power_spi_disable();
    power_timer0_disable();
    power_timer2_disable();
    power_twi_disable();  
    sleep_cpu();
    power_all_enable();
    sleep_disable();
  }
  
}
 
ISR(WDT_vect)
{
  return;
}
