/*
 * File:   main.c
 * Author: SERVARIVERA
 *
 * Created on 1 de octubre de 2018, 07:25 PM
 */

#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000

void main(void) {
    //OSCILADOR
    OSCFRQbits.HFFRQ = 0b110;
    
    //PUERTOS
    PORTC=0; //LIMPIA TODO PUERTO A
    ANSELC=0; //TODO PUERTO A COMO DIGITAL
    TRISC=0; // PUERTO C COMO SALIDA
    
    PORTB=0; //LIMPIA TODO PUERTO A
    ANSELB=0; //TODO PUERTO A COMO DIGITAL
    TRISB=0; // PUETO B COMO SALIDA
    
    PORTA=0; //LIMPIA TODO PUERTO B
    ANSELA=0; //TODO PUERTO B COMO DIGITAL 
    TRISA=255; //PUERTO A COMO ENTRADA
    
    //WPUB=1;
    //WPUC=1;
    //WPUA=1;
    
    //
    T0CKIPPS=0x0D; //BOTON UBICADO EN RA6
    T0CON0bits.T016BIT=0; // TIMER DE 8 BITS
    T0CON0bits.T0OUTPS=0b0000; // POS 1:1
    T0CON1bits.T0CS=0b001; // CS FOSC/4
    T0CON1bits.T0ASYNC=1; //NO ESTA SINCRONIZADA
    T0CON1bits.T0CKPS=0b0000; //PRE 1111111:4096
    TMR0H=9; //PRECARGA  
    TMR0L=0; // EL CONTADOR SE INCIA EN CERO
    T0CON0bits.T0EN=1; //TIMER TMR0 HABILITADO
    
    unsigned char numero[] = {0b11111100, 0b01100000,
                              0b11011010, 0b11110010,  
                              0b01100110, 0b10110110, 
                              0b10111110, 0b11100000, 
                              0b11111110, 0b11100110};
    
    //CICLO INFINITO
    while(1){
        //CICLO DE CONTEO DE 0---->10 
        if(TMR0L <= 10){
            LATC= 0b00000110; // 
            LATB=numero[TMR0L]; // 
            __delay_us(200); 
        }
        //CICLO DE CONTEO DE 10---->20 
        if(TMR0L >= 10 && TMR0L < 20){ 
            LATC=0b00000110;
            LATB = numero[TMR0L-10];
            __delay_us(200);
                
            LATC=0b00000101; //INDICACION DE CAMBIO DE UNIDAD A DECENA 
            LATB=numero[1];  
            
            __delay_us(200);
        }
        //CICLO DE CONTEO DE 20---->30 
        if(TMR0L >= 20 && TMR0L < 30){
            LATC= 0b00000110; //DISPLAY 1 ENCENDIDO 
            LATB = numero[TMR0L-20]; 
            __delay_us(200);
            
            LATC =0b00000101; //
            LATB= numero[2];
            
            __delay_us(200);
        }
        //CICLO DE CONTEO DE 30---->40 
        if(TMR0L >= 30 && TMR0L < 40){
            LATC= 0b00000110;
            LATB = numero[TMR0L-30];
            __delay_us(200);
            
            LATC =0b00000101;
            LATB= numero[3];
            
            __delay_us(200);
        }
        //CICLO DE CONTEO DE 40---->50 
         if(TMR0L >= 40 && TMR0L < 50){
            LATC= 0b00000110;
            LATB = numero[TMR0L-40];
            __delay_us(200);
            
            LATC =0b00000101;
            LATB= numero[4];
            
            __delay_us(200);
        }
        //CICLO DE CONTEO DE 50---->60 
         if(TMR0L >= 50 && TMR0L < 60){
            LATC= 0b00000110;
            LATB = numero[TMR0L-50];
            __delay_us(200);
            
            LATC =0b00000101;
            LATB= numero[5];
            
            __delay_us(200);
        }
        //CICLO DE CONTEO DE 60---->70 
         if(TMR0L >= 60 && TMR0L < 70){
            LATC= 0b00000110;
            LATB = numero[TMR0L-60];
            __delay_us(200);
            
            LATC =0b00000101;
            LATB= numero[6];
            
            __delay_us(200);
        }
        //CICLO DE CONTEO DE 70---->80 
         if(TMR0L >= 70 && TMR0L < 80){
            LATC= 0b00000110; 
            LATB = numero[TMR0L-70];
            __delay_us(200);
            
            LATC =0b00000101;
            LATB= numero[7];
            
            __delay_us(200);
        }
        //CICLO DE CONTEO DE 80---->90 
         if(TMR0L >= 80 && TMR0L < 90){
            LATC= 0b00000110;
            LATB = numero[TMR0L-80];
            __delay_us(200);
            
            LATC =0b00000101;
            LATB= numero[8];
            
            __delay_us(200);
        }
        //CICLO DE CONTEO DE 90---->100 
         if(TMR0L >= 90 && TMR0L < 100){
            LATC= 0b00000110;
            LATB = numero[TMR0L-90];
            __delay_us(200);
            
            LATC =0b00000101;
            LATB= numero[9];
            
            __delay_us(200);
        }
        //CICLO DE CONTEO FINAL Y REINICIO. 
         if(TMR0L >= 100){
            LATC= 0b00000011;
            LATB = numero[1];
            
            __delay_us(200);
            
            LATC =0b00000101;
            LATB= numero[0];
            __delay_us(200);
            
            LATC =0b00000110;
            LATB= numero[0];
            __delay_us(200);
        }
       }
    return;
}

