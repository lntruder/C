#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int check_arguments(int argc, char **argv){                         // funkcja przyjmuje argumenty podawane w konsoli i informacje o ich ilosci
    if (argc > 4){                                                  // sprawdza poprawnosc argumentow
        help_meenu(-1);
        return 0;}
    int only_one = 0, numer_argumentu = -1;
    for (int j = 1; j < argc; j++){
        int kontrolna = 0;
        for (int i = 0; i < strlen(argv[j]); i++){
            if (isdigit(argv[j][i]) != 0){
                kontrolna++;
            }
            if (kontrolna == strlen(argv[j])){
                numer_argumentu = j;                                // do zmiennej numer_argumentu, ktora bedzie zwracana przez funkcje
                only_one++;                                         // wpisuje sie numer pozycji argumentu skladajacego sie tylko z cyferek
            }
        }
    }
    if (only_one != 1){
        if (only_one == 0){                                         // funkcja zwroci poprawna wartosc tylko gdy bedzie jeden argument liczbowy
            help_meenu(-4);
            return -1;
        }
        help_meenu(-5);
        return -1;}
       int kontrolka = 0;
    for (int j = 1; j < argc; j++){                                  // sprawdzenie argumentow na obecnosc -h
        if (strcmp(argv[j],"-h") == 0){
            kontrolka++;
            if (argc <= 3){                                          // gdy -h i argumentow mniej niz 3 - brak nazwy pliku (brak liczby wykluczony wczesniej)
                help_meenu(-3);
                return -1;
            }
            help_meenu(0);
        }
    }
    if ((kontrolka == 0) && (argc == 4)) {
        help_meenu(-6);
        return -1;
    }
    return numer_argumentu;
}
