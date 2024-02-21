#include "PAGE.h"

// Function to perform page eviction using FCFS logic
void FCFS_FUNCTION(LISTOFPAGES* plFCFS) {
    page* PITFCF = plFCFS->HDL;
    page* PG_FCFFSEVICtion = plFCFS->HDL;

    while (PITFCF) {
        // Compare the time the pages were brought into memory
        if (PITFCF->FTBOUGHT < PG_FCFFSEVICtion->FTBOUGHT) {
            PG_FCFFSEVICtion = PITFCF;
        }
        PITFCF = PITFCF->next;
    }

    if (DEBUG == 1)
        printf("EVICTED ones :: p[%03d] c:%02d l:%02f\n", PG_FCFFSEVICtion->pid, PG_FCFFSEVICtion->CNTER, PG_FCFFSEVICtion->LONE);

    PG_FCFFSEVICtion->pid = -1;
    PG_FCFFSEVICtion->PGENUMBER = -1;
}

