
#include "driver.h"



int main()
{

    Driver_Init();

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