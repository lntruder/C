#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void help_meenu(int o){                            // funkcja wyswietlajaca menu pomocy
    printf(" -- Help -- \n");
    printf("To okno wyswietla sie gdy podasz parametr -h, lub wprowadzisz bledne dane\n");
    printf("\n instrukcja: \n");
    printf("1. Dopuszczalne sa maksymalnie 3 parametry\n");
    printf("2. Do poprawnej pracy programu wymagane sa nastepujace parametry : \n");
    printf("  - liczba (parametr do obliczenia Kodu Graya) \n  - nazwa pliku (do zapisu wyniku dzialania programu) \n");
    printf("  - (opcjonalnie) parametr -h (wyswietla to okno) \n");
    printf("3. Kolejnosc wpisania argumentow nie ma znaczenia \n");
    printf("4. Argumenty trzeba rozdzielic spacjami");
    printf("\n -- Help -- \n");

    if (o == -1){                               // + dodatkowe porady zale¿ne od okolicznoœci
        printf("\n Wprowadziles zbyt duzo argumentow, sprobuj ponownie \n");
    }
    if (o == -2){
        printf("\n Wprowadzone argumenty sa bledne, zapoznaj sie z oknem help \n");
    }
    if (o == -3){
        printf("\n Nie wprowadziles nazwy pliku \n");
    }
    if (o == -4){
        printf("\n Nie wprowadziles zadnej liczby \n");
    }
    if (o == -5){
        printf("\n Wprowadziles za duzo liczb \n");
    }
    if (o == -6){
        printf("\n Wprowadziles za duzo argumentow nazwy pliku");
    }
    printf("\n\n\n");
}
