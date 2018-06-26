#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct lista{
    struct lista *next;
    int x;
}el_listy;

el_listy *first, *tmp;

int math_power_of_2(int x){      // funkcja zwracajaca wartosci potegi 2^n
    int n;
    n = 1;
    while(x > 0){
        n = n + n;
        x--;
        }
return n;
}

int get_value(el_listy *wsk, int n){ // funkcja przyjmuje wskaünik na pierwszy element listy i numer
    if (n == 0){
        return 0;
    }
    else{
    for (int i = 0; i < n; i++){    // szukam w liscie n elementu liczac od 1 elementu listy
        wsk = wsk -> next;
        }
    return wsk -> x;                // funkcja zwraca wartosc przechowywana w n elemencie listy
    }
}



el_listy* gen_list(int n){  // funkcja dynamicznie rezerwujaca pamiec dla zadanego n (w ilosci 2^n)

    el_listy *wsk = malloc(sizeof(el_listy));
    wsk -> next = NULL;
    if (n == 1){
        el_listy *nowy = malloc(sizeof(el_listy));
        nowy -> x = 0;
        wsk -> x = 1;
        nowy -> next = wsk;
        wsk -> next = NULL;
        wsk = nowy;
        nowy = NULL;
       return wsk;
    }
    else{
        int p = math_power_of_2(n);
        for (int i = 1; i < p; i++){
            el_listy *nowy = malloc(sizeof(el_listy));
            nowy -> next = wsk;
            wsk = nowy;
            nowy = NULL;
        }
        return wsk;
    }
}

el_listy *gen_gray(el_listy *wsk, int n){   // rekurencyjny generator kodu graya (w systemie decymalnym)

        el_listy* head;
        if (n == 1){
            wsk -> x = 0;
            wsk -> next -> x = 1;
        }
        else{
            int p;
            gen_gray(wsk, n - 1);
            p = math_power_of_2(n-1);
            head = wsk;
            for (int i = p; i < p + p; i++){
                wsk = head;
                for (int j = 0; j < i; j++){
                    wsk = wsk -> next;
                }
                    wsk -> x = p + get_value(head, p + p - i - 1);
                    wsk = head;
            }
        }

        return wsk;                    // funkcja zwraca wskaznik na pierwszy element listy wypelnionej kodem graya
}


