#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include"studio.h"
#include"report.h"
#include"utils.h"

int main()
{
    int scelta, stato;
    char nomestudio[100];
    Studio studio;
    List lista = newList();

    printf("Benvenuto nel monitoraggio dello studio!\n");
    sleep(1);
    printf("Questo programma ti permette di tenere traccia dei tuoi studi e delle tue scadenze.\n");
    sleep(1);
    printf("Puoi inserire nuovi studi, visualizzare quelli esistenti e generare report.\n");
    sleep(1);
    
    do
    {
        printf("Per creare un attivita' premi 1.\n");
        printf("Per visualizzare il report, premi 2.\n");
        printf("Per aggiornare il progresso di uno studio, premi 3.\n");
        printf("Per uscire, digita 0.\n");
        printf("Inserisci la tua scelta: ");
        scanf("%d", &scelta);

        switch(scelta)
        {
            case 1:  //Caso per inserire un nuovo studio
                system("clear");       
                printf("Inserimento di un nuovo studio...\n");
                sleep(2);
                studio = inputStudio();
                if (studio == NULL) 
                {
                    printf("Errore nell'inserimento dello studio.\n");
                    break;
                } 
                else 
                {
                    addHead(lista, studio);
                    system("clear");
                    printf("Studio inserito con successo!\n\n");
                    
                    printf("Lista degli studi:\n");
                    printList(lista);
                    printf("\n\n");
                } break;

            case 2: //Caso per generare il report
                system("clear");
                printf("Generazione del report...\n");
                sleep(2);
                system("clear");
                if(isEmpty(lista)) 
                {
                    printf("La lista degli studi è vuota. Non è possibile generare un report.\n");
                    break;
                }
                else
                {
                    generaReport(lista);
                    monitoraggioData(lista);
                    printf("Report generato con successo!\n\n");
                }                
                break;

            case 3: //Caso per aggiornare il progresso di uno studio
                system("clear");
                while(getchar() != '\n');
                printf("Inserisci il nome dello studio da aggiornare: ");
                fgets(nomestudio, sizeof(nomestudio), stdin);
                nomestudio[strcspn(nomestudio, "\n")] = 0; // rimuove newline

                printf("Inserisci il nuovo stato (-1 = non iniziata, 0 = in corso, 1 = completata): ");
                scanf("%d", &stato);
                while(getchar() != '\n'); //Pulisce buffer input

                aggiornaCompletamentoNome(lista, nomestudio, stato);

                                
                break;    

            case 0: //Caso per uscire
                system("clear");
                printf("CIAO.\n");
                sleep(2);
                system("clear");
                freeList(lista);
                break;
            default:    //Caso per scelta non valida
                system("clear");
                printf("Scelta non valida. Riprova.\n");
        }
    }while(scelta != 0);
}