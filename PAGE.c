#include "PAGE.h"
// Initialize the page list with free pages
void Intializing_PGELIst(LISTOFPAGES* pl) {
    pl->HDL = malloc(sizeof(page));
    page* it = pl->HDL;
    int i;
    for(i=0;i<Toal_PAGE;i++) {
        it->pid = -1; it->PGENUMBER = -1;
        it->next = NULL;
        if(i < 99) {
            it->next = malloc(sizeof(page));
            it = it->next;
        }
    }
}

// Display all Pages
void PageeDisplayingg(LISTOFPAGES* pl) {
    page* it = pl->HDL;
    int cnt = 0;
    while(it) {
        printf(it->pid > 0 ? "|*| p[%03d] c:%02d l:%02f |*|" : "|*                  |",it->pid, it->CNTER, it->LONE);
        cnt++;
        if((cnt % 10) == 0) printf("\n");
        it = it->next;
    }
    printf("\n");
}
// Free Pages
int PageWhoRFree(LISTOFPAGES* pl,int CNTER) {
    page* it = pl->HDL;
    while(it) {
        if(it->pid == -1) { // page not being used by any process;
            CNTER--;
        }
        if(!CNTER) return 1;
        it = it->next;
    }
    return 0;
}

// Memory in Pages
int MEMinPGES(LISTOFPAGES* pl,int pid,int PGENUMBER) {
    page* it = pl->HDL;
    while(it) {
        if(it->pid == pid && it->PGENUMBER == PGENUMBER) return 1;
        it = it->next;
    }
    return 0;
}


page* PAGEfrreeeg(LISTOFPAGES* pl) {
    page* it = pl->HDL;
    while(it) {
        if(it->pid == -1) return it;
        it = it->next;
    }
    return NULL;
}
//Memeory Getting Free
void MEMRFree(LISTOFPAGES* pl,int pid) {
    page* it = pl->HDL;
    while(it) {
        if(it->pid == pid) {
            it->pid = -1;
            it->PGENUMBER = -1;
        }
        it = it->next;
    }
}
// Next Page Number

int PGNUMNXT(int curr_page_no,int max_page_size) {
    int x = rand()%10;
    if(x < 7) {
        x = curr_page_no+(rand()%3)-1 < 0;
    } else {
        x = rand()%max_page_size;
        while(abs(x-curr_page_no) <= 1) x = rand()%max_page_size;
    }
    if(x < 0) x = 0;
    if(x >= 100) x = max_page_size-1;
    return x;
}

// Free Page ID
page* IDwhozPGrFree(LISTOFPAGES* pl,int pid,int PGENUMBER) {
    page* it = pl->HDL;
    while(it) {
        if(it->pid == pid && it->PGENUMBER == PGENUMBER) return it;
        it = it->next;
    }
    return NULL;
}

// Comparing Arrival Time
int CMP_ARRtime(const void* a,const void* b) {
    return ((process*)a)->TIMEARR - ((process*)b)->TIMEARR;
}
