
#include "driver.h"
#include "driver_cfg.h"
#include <stdio.h>

Driver rx, tx;

void Callback(uint8_t *data)
{
    printf("\nReceived : ");
    for (uint8_t i = 0; i < 8; i++)
        printf("0x%x ", data[i]);
    printf("\n ");

    data[0] = data[0] | 0x40;

    Driver_Write(&tx,data);
}

int main()
{
     printf("Program started \n ");

    Driver_Init(&rx, CAN_TO_PRG, Callback);
    Driver_Init(&tx, CAN_TO_SIM, NULL);

    while (1)
    {
        /* code */
    }

    /*
    pthread_t BusRxTh, BusTxTh, ProgramTh;

    pthread_create(&BusRxTh, NULL, bus_rx, NULL);
    pthread_create(&BusTxTh, NULL, bus_tx, NULL);
    pthread_create(&ProgramTh, NULL, program, NULL);

    pthread_join(BusRxTh, NULL);
    pthread_join(BusTxTh, NULL);
    pthread_join(ProgramTh, NULL);
*/
    return 0;
}