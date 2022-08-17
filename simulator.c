
#include <stdio.h>
#include "driver_cfg.h"
#include "driver.h"

Driver rx, tx;

void Callback(uint8_t *data)
{
    printf("\nReceived : ");
    for (uint8_t i = 0; i < 8; i++)
        printf("0x%x ", data[i]);
    printf("\n ");
}

int main()
{
    printf("Simulator started \n ");

    uint8_t data[8];
    Driver_Init(&rx, CAN_TO_SIM, Callback);
    Driver_Init(&tx, CAN_TO_PRG, NULL);


    while (1)
    {
        printf("\nInput 8 bytes : ");

        for (int i = 0; i < 8; i++)
        {
            printf("%d -> ",i);
            scanf("%hhx", &data[i]);
        }

        printf("\n");

        Driver_Write(&tx, data);
    }

    return 0;
}