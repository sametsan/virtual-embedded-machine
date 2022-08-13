#include "driver.h"
#include <sys/shm.h>
#include <stdint.h>
#include <stdio.h>
#include <signal.h>
#include "driver_cfg.h"

static int memID;
static Driver_Buffer *memory;

void _Driver_Init()
{
    signal(SIGINT, Driver_Intterrupt);

    memID = shmget(CAN0, sizeof(Driver_Buffer), 0644 | IPC_CREAT);
    memory = (Driver_Buffer *)shmat(memID, NULL, 0);
    memory->state = false;
}

void Driver_Write(uint8_t *data)
{
    for (uint8_t i = 0; i < MEMORY_SIZE; i++)
    {
        memory->data[i] = data[i];
        memory->state = true;
    }
}

void Driver_Intterrupt()
{

    if (memory->state == true)
    {
        uint8_t data[MEMORY_SIZE];

        /// Proccesss START
        for (uint8_t i = 0; i < MEMORY_SIZE; i++)
            data[i] = memory->data[i];

        memory->state = false;

        for (uint8_t i = 0; i < MEMORY_SIZE; i++)
            printf("0x%x ", data[i]);
        printf("\n ");

        data[0] = data[0] + 0x40;
        Driver_Write(data);
        ///// Proccesss END
    }
}
