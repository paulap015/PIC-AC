#include <xc.h>
#include <stdio.h>
#include <pic18f4550.h>

void iniciar_pic() {
    OSCILADOR_INTERNO = OCHO_MHZ;
    OSCILADOR_DEL_SISTEMA = 0b10; //?
    OSCCON = OCHO_mHz;
    PULL_UP = ACTIVADO;
}

void iniciar_emoticones() {

    unsigned char temperatura[8] = {
        0b00100,
        0b10101,
        0b01110,
        0b11111,
        0b01110,
        0b10101,
        0b00100,
        0b00000,
    };

    /*Emoticon a mostrar*/
    unsigned char distancia[8] = {
        0b00000,
        0b00000,
        0b00100,
        0b00010,
        0b11111,
        0b00010,
        0b00100,
        0b00000,
    };

    unsigned char luz[8] = {
        0b01010,
        0b01010,
        0b01010,
        0b11111,
        0b10001,
        0b01110,
        0b00100,
        0b00100,
    };

    unsigned char todo_bien[8] = {
        0b00000,
        0b01010,
        0b01010,
        0b00000,
        0b11111,
        0b01110,
        0b00100,
        0b00000,
    };


    LCD_Custom_Char(4, todo_bien);
    LCD_Custom_Char(5, temperatura);
    LCD_Custom_Char(6, distancia);
    LCD_Custom_Char(7, luz);


}

void imprimir(int dist, int temp, int luz) {

    // imprimir_emoticon();
    LCD_String_xy(0, 0, "D:T:L:");
    /*Distancia*/
    char aux_dist[16] = "";
    sprintf(aux_dist, "%dcm", dist);
    /*Temp*/
    char aux_temp[16] = "";
    sprintf(aux_temp, "%dG", temp);
    /*Luz*/
    char aux_luz[16] = "";
    sprintf(aux_luz, "%dP", luz);
    //__delay_ms(100);
    LCD_Command(0xC0);
    LCD_String_xy(3, 0, aux_dist);
    LCD_String_xy(3, 6, aux_temp);
    LCD_String_xy(3, 11, aux_luz);
    __delay_ms(900);
    LCD_Clear();
}

