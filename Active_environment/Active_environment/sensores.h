/* 
 * File:   sensores.h
 * Author: ASUS
 *
 * Created on 1 de octubre de 2021, 16:53
 */

#ifndef SENSORES_H
#define	SENSORES_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h> // include processor files - each processor file is guarded.  
#include <pic18f4550.h>
#include "fuses.h"
#include <stdio.h>
#include <stdint.h>
#include "adc_lib.h"
    
//Nuevas def
#define ECHO TRISCbits.RC1
#define TRIG TRISCbits.RC0
#define LEC_TRIG PORTCbits.RC0
#define LEC_PULSOECHO PORTCbits.RC1
#define ESC_ECHO LATCbits.LATC1
#define ESC_TRIG LATCbits.LATC0

//Variables sensores 
unsigned int val_distancia = 0;
int sensor_distancia(void);
unsigned int obtener_distancia(void);
void init_ports(void);

    //Variables de temperatura 
    int val_temp = 0;
    uint16_t value_adc;
    int sensor_temperatura(void);

    //Variables de luz 
    uint16_t val_intensidad;
    int val_luminosidad = 0;
    int sensor_Luz(void);

#ifdef	__cplusplus
}
#endif

#endif	/* SENSORES_H */

