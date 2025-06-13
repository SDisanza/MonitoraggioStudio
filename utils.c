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

int dataValida(int data) 
{
    /*
        Questa funzione verifica se una data è valida e nel formato AAAAMMGG.
        Restituisce 1 se la data è valida, altrimenti 0.
    */
    int anno = data / 10000;
    int mese = (data / 100) % 100;
    int giorno = data % 100;
    int giorniMese[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    if ((mese < 1 || mese > 12) || (giorno < 1 || giorno > 30)) 
    {
        return 0;
    }

    // Anno bisestile
    if (mese == 2 && ((anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0))) 
    {
        if (giorno > 29) return 0;
    } 
    else 
    {
        if (giorno > giorniMese[mese - 1]) return 0;
    }

    return 1;
}
