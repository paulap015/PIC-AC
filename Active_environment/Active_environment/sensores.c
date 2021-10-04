#include "sensores.h"

int sensor_distancia(void) {
    init_ports();
    val_distancia = obtener_distancia();
    if (val_distancia <= 38 && val_distancia > 12)
        val_distancia += 2;
    else if (val_distancia > 38)
        val_distancia += 3;
    else if (val_distancia <= 12)
        val_distancia--;
    return (int) val_distancia;
}

void init_ports() {
    ADCON1bits.PCFG = 0xF;
    ESC_ECHO = 0;
    ESC_TRIG = 0;
    ECHO = 1; //Echo
    TRIG = 0; //Trigger
}

unsigned int obtener_distancia(void) {
    unsigned int cm = 0;
    ESC_TRIG = 1;
    __delay_us(10); /*Generación de ondas (Pulsos para la lectura)*/
    ESC_TRIG = 0;
    while (LEC_PULSOECHO == 0) {
    };
    while (LEC_PULSOECHO == 1) {
        cm++;
        __delay_us(58);
    }
    return cm;
}

int sensor_temperatura(void) {
    TRISAbits.RA0 = 1; //Pin_A0 puesto en ALTO. 
    adc_init10Bits(0);
    value_adc = adc_read10Bits(); //  Lectura de valor AD.*/; 
    val_temp = (int) value_adc * 0.4887;
    return val_temp;
}

//Metodo de la temperatura 

int sensor_luz(void) {

    TRISAbits.TRISA1 = 1; //entrada puerto A1 

    adc_init10Bits(1);

    val_intensidad = adc_read10Bits(); //  Lectura de valor AD.*/; 
    val_intensidad = (val_intensidad * 5) / 1024;
    val_luminosidad = (val_intensidad * 100) / 5;

    return val_luminosidad;
}

