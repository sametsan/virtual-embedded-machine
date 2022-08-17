#include "driver.h"
#include <sys/shm.h>

static void *Driver_IRQ_Thread(void *arg)
{

    Driver *memory = (Driver *)arg;

    while (1)
    {
        if (memory->buffer->IRQ_state == true)
        {
            memory->IRQ_callback(memory->buffer->data);
            memory->buffer->IRQ_state= false;
        }
    }
}

void Driver_Init(Driver *memory, key_t key, void (*IRQ_callback)(uint8_t *data))
{
    static int memID;
    memID = shmget(key, sizeof(Buffer), 0644 | IPC_CREAT);
    memory->buffer = (Buffer *)shmat(memID, NULL, 0);
    memory->buffer->IRQ_state = false;
    memory->IRQ_callback = IRQ_callback;

    if (IRQ_callback != NULL)
    {
        pthread_create(&(memory->IRQ_thread), NULL, Driver_IRQ_Thread, memory);
      //  pthread_join(memory->IRQ_thread, NULL);
    }
}

void Driver_Write(Driver *memory, uint8_t *data)
{
    for (uint8_t i = 0; i < 8; i++)
        memory->buffer->data[i] = data[i];
    memory->buffer->IRQ_state = true;

}
