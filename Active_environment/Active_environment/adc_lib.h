/* 
 * File:   adc_lib.h
 * Author: ASUS
 *
 * Created on 28 de septiembre de 2021, 12:38
 */

#define HACER_CONVERSION ADCON0bits.GO_DONE
#define RESULTADO ADRESH
#define CANAL_0 0b0000
#define CANAL_1 0b0001
#define CANAL_A_TRABAJAR ADCON0bits.CHS
#define ENTRADA_PUERTO ADCON1bits.PCFG
#define ENTRADA_ANALOGICA 0b1101
#define VOLTAJE_REFERENCIA ADCON1bits.VCFG
#define CERO_VOLTIOS_CINCO_VOLTIOS 0b00 
#define TIEMPO_ADQUISICION ADCON2bits.ACQT
#define TIEMPO_CONVERSION ADCON2bits.ADCS
#define MODULO_AD ADCON0bits.ADON
#define HABILITADO 1
#define DESHABILITADO 0
#define JUSTIFICACION ADCON2bits.ADFM
#define DERECHA 1
#define IZQUIERDA 0
#define INICIAR 1

#ifndef ADC_LIB_H
#define	ADC_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    void adc_init8Bits(int canal); 
    unsigned char adc_read8Bits();
    
    void adc_init10Bits(int canal);  
    unsigned int adc_read10Bits();  
    
    void adc_config(); 
    
#ifdef	__cplusplus
}
#endif

#endif	/* ADC_LIB_H */

