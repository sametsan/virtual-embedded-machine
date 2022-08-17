#ifndef DRIVER_H
#define DRIVER_H

#include <stdbool.h>
#include <stdint.h>
#include <pthread.h>
#include <sys/ipc.h>

typedef struct
{
    uint8_t data[8];
    bool IRQ_state;
} Buffer;

typedef struct
{
    Buffer *buffer;
    pthread_t IRQ_thread;
    void (*IRQ_callback)(uint8_t *data);
} Driver;

void Driver_Init(Driver *memory, key_t key, void (*IRQ_callback)(uint8_t *data));
void Driver_Write(Driver *memory, uint8_t *data);

#endif