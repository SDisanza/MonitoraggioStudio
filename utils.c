#include<stdio.h>
#include<time.h>

int dataOggi()
{
    /*
        Questa funzione calcola la data odierna nel formato AAAAMMGG 
        (es. 20231005 per il 5 ottobre 2023).
        Restituisce un intero che rappresenta la data odierna.
    */

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int data = (tm.tm_year + 1900) * 10000 + (tm.tm_mon + 1) * 100 + tm.tm_mday;

    return data;
}