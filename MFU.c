#include "PAGE.h"
// Function to perform page eviction using LRU logic
void MFU_FUNCTION(LISTOFPAGES* PMFUL) {
    page* FITMFU = PMFUL->HDL;
    page* PGMFUEVC = PMFUL->HDL;
    int max = FITMFU->CNTER;
        // Iterate through the list of pages
    while(FITMFU) {
        if(FITMFU->CNTER > max){
            PGMFUEVC = FITMFU;
            max = FITMFU->CNTER;
        }
        FITMFU = FITMFU->next;
    }
    if (DEBUG==1) printf("EVICTED: p[%03d] c:%02d l:%02f\n", PGMFUEVC->pid, PGMFUEVC->CNTER, PGMFUEVC->LONE);
    PGMFUEVC->pid = -1;
    PGMFUEVC->PGENUMBER = -1;
}
