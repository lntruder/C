#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "gen_list.h"


void display_gray(el_listy *kopialisty, int n){
    int decimal_gray;
    char wyraz[n];
    for (int i = 0; i < math_power_of_2(n); i++){
        wyraz[0] = '\0';
        decimal_gray = get_value(kopialisty, i);
        for (int j = 0; j < n; j++){
            if (decimal_gray % 2 == 0){
                strcat(wyraz,"0");
            }
            else
            {
                strcat(wyraz,"1");
            }
            decimal_gray = decimal_gray/2;
        }
    printf("%s", strrev(wyraz));
    printf("\n");
  }
}
