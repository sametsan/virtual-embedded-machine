#ifndef DRIVER_CFG_H
#define DRIVER_CFG_H

#include <stdint.h>
#include <stdbool.h>

#define MEMORY_SIZE 8

#define CAN0 0x01
#define CAN1 0x02


typedef struct 
{
    bool state;
    uint8_t data[MEMORY_SIZE];
}Driver_Buffer;



#endif