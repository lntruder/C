#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "help_menu.h"
#include "check_arguments.h"
#include "display_gray.h"
#include "get_file_name.h"
#include "save_to_file.h"
#include "gen_list.h"

int main(int argc, char **argv){

    int n;
    int wartosc;
    n = check_arguments(argc, argv);   // sprawdzenie poprawnosci zadanych argumentow
    if (n < 1){
        return 0;
    }
    if (argc == 2){
        help_meenu(-3);
        return 0;
    }
    wartosc = atoi(argv[n]);
    el_listy* kopia;

    kopia = gen_list(wartosc);          // generacja listy
    kopia = gen_gray(kopia, wartosc);   // wypelnienie listy decymalnym kodem graya

    display_gray(kopia, wartosc);
    char* nazwa = get_file_name(argc, argv, n);

    if (save_to_file(nazwa, wartosc, kopia) != 0){
        printf("Nie udalo sie otworzyc pliku");
    }

    el_listy *p;
    while(kopia != NULL){
        p = kopia;
        kopia = kopia -> next;
        p = NULL;
        free(p);
    }


return 0;
}
