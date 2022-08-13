#include <stdint.h>
#include <sys/shm.h>
#include <stdio.h>
#include "driver_cfg.h"
#include <pthread.h>

static int memID;
static Driver_Buffer *memory;

void *send(void *arg)
{
    while (1)
    {
        printf("\n 8 bytes input : ");
        for (int i = 0; i < MEMORY_SIZE; i++)
            scanf("%hhx", &memory->data[i]);

        printf("\n ");
    }
}

void *receive(void *arg)
{
    while (1)
    {
        if (memory->state == true)
        {
            printf("\n Receive : ");
            for (uint8_t i = 0; i < MEMORY_SIZE; i++)
                printf("0x%x ", memory->data[i]);
            printf("\n ");

            memory->state = false;
        }
    }
}

int main()
{
    memID = shmget(CAN0, sizeof(Driver_Buffer), 0644 | IPC_CREAT);
    memory = (Driver_Buffer *)shmat(memID, NULL, 0);
    memory->state=false;
/*
    pthread_t rx, tx;

    pthread_create(&rx, NULL, receive, NULL);
    pthread_create(&tx, NULL, send, NULL);

    pthread_join(rx, NULL);
    pthread_join(tx, NULL);

    shmdt(memory);*/
    return 0;
}