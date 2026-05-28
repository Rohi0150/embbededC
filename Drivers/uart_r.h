#ifndef UART_R_H
#define UART_R_H

#include "gpio.h"
#include "timer0.h"
#include "timer1.h"

/* 
Baud Rate  : 9600
   TX Pin     : PF0
Frame Format:
   1 Start Bit
   8 Data Bits
   1 Stop Bit 
*/
/* PF0 configured as TX output pin.
   UART idle state remains HIGH. */
void uart_init(){
  init_pin(F,OUT,0);
  out_pin(F,0,high);
}
/* Timer1 is used to generate 104us bit delay. */
void delay_104us1(){
  timer1_ctc(1568, TIMER1_PRES_1);
  timer1_comp_delay(1);
  timer1_stop();
}

void tx_char1(char x){
  //start bit:
  out_pin(F,0,low);
  delay_104us1();
  //data bits(8) :
  for (int i = 0; i < 8; i++)
  {
      if (x & (1 << i))
          out_pin(F, 0, high);
      else
          out_pin(F, 0, low);

      delay_104us1();
  }
  //stop bit (1):
  out_pin(F, 0, high);
  delay_104us1();
}
//To send a String via 
void tx_str1(const char *s)
{
    //Sends characters continuously until NULL character.
    while (*s != '\0')
    {
        tx_char1(*s);
        s++;
    }
}
//TODO : Receiver end (RX)
#endif

