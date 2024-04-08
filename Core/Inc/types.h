/*
************************************************************
* NOTE: Automatically generated file. DO NOT MODIFY!
************************************************************
*
* File: speed_regulation.h
*
* Code generated from model             : 'pmsm_closed_loop_svpwm_control'.
* Subsystem selected for code generation: 'speed_regulation'.
*
* Schematic Editor version              : 2024.1
* C source code generated on            : 22-Mar-2024 @ 04:54:52 PM
*
*/

#include<math.h>
#include<stdint.h>

// Map internal types to C standard types
typedef unsigned char X_UnInt8;   // uint8_t from C standard lib
typedef unsigned short X_UnInt16; // uint16_t from C standard lib
typedef unsigned int X_UnInt32;   // uint32_t from C standard lib

#ifndef PLATFORM_INFO
#define PLATFORM_NAME "generic"
#endif

#ifndef SPEED_REGULATION_TYPES_H
#define SPEED_REGULATION_TYPES_H

#include "custom_types.h"

// generated using template:generic_macros.template-----------------------------------------
/*********************** Macros (Inline Functions) Definitions ***************************/

// ----------------------------------------------------------------------------------------

#ifndef MAX
#define MAX(value, limit) (((value) > (limit)) ? (value) : (limit))
#endif
#ifndef MIN
#define MIN(value, limit) (((value) < (limit)) ? (value) : (limit))
#endif


#ifndef SPEED_REGULATION_CUSTOM_TYPES_H
// Use default types
typedef int int_t;
typedef unsigned int uint_t;
typedef double real_t;
#endif

#endif
