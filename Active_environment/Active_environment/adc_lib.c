
#include <xc.h>
#include "adc_lib.h"

void adc_init8Bits(int canal){
    //ADC de 8bits
    adc_config(canal);  
    JUSTIFICACION = IZQUIERDA; 
}

unsigned char adc_read8Bits(){
    
    HACER_CONVERSION = INICIAR; 
    while (HACER_CONVERSION); 
    return RESULTADO; 
}  

void adc_config(int canal){
    ENTRADA_PUERTO = ENTRADA_ANALOGICA; 
    VOLTAJE_REFERENCIA = CERO_VOLTIOS_CINCO_VOLTIOS;
    if(canal == 0) { CANAL_A_TRABAJAR = CANAL_0; } else{ CANAL_A_TRABAJAR = CANAL_1;};  
    TIEMPO_ADQUISICION = 0b010; //?
    TIEMPO_CONVERSION = 0b001; //?
    MODULO_AD = HABILITADO; 
}

void adc_init10Bits(int canal){
    
    adc_config(canal);  
    JUSTIFICACION = DERECHA; 
} 
unsigned int adc_read10Bits() {
    unsigned int value_adc = 0;
    HACER_CONVERSION = INICIAR; 
    while (HACER_CONVERSION); 
    value_adc = RESULTADO; 
    value_adc = (value_adc << 8) + ADRESL;
    return value_adc;  
}