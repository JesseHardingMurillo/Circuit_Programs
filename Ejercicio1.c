// El programa realiza lectura de la entrada anlogica AN0 que en este casao el elemento analogico es un Potenciometro y esto simula un sensor analogico
#include <16f873a.h>
#fuses HS,NOWDT,BROWNOUT,NOLVP,NOPROTECT
#device ADC = 10 //Cree un dispositivo a adc de 10 bits
#use delay(clock = 20M)
#use standard_io(C)

#define lcd_rs_pin         Pin_C0
#define lcd_rw_pin         Pin_C1
#define lcd_enable_pin     Pin_C2
#define lcd_data4          Pin_C4
#define lcd_data5          Pin_C5
#define lcd_data6          Pin_C6
#define lcd_data7          Pin_C7

#include <LCD.c>
#define S_Temperatura AN0



//long valor_adc;
//float temperatura;

void main()
{
   lcd_init();
   setup_adc_ports(S_Temperatura);
   setup_adc(ADC_CLOCK_INTERNAL);
   set_adc_channel(0);//lectura Vout del sensor de temperatura en pin AN0
   
   int16 sensor;
   while(TRUE)
   {
      sensor=read_adc();//lectura del valor
      sensor=(5*sensor*100)/1023;
      lcd_gotoxy(1,1);
      printf(LCD_PUTC, "TEMPERATURA");
      lcd_gotoxy(1,2); 
      printf(LCD_PUTC,"%ld GRADOS C",sensor);
      delay_ms(200);
   }
}
