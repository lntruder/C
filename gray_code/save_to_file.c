#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int save_to_file(char* file_name, int i, el_listy *wsk)
{
	FILE *plik;
	plik = fopen(file_name, "w");
	if (plik == NULL){
        return -1;
	}
    int j = 0;
    int decimal_gray;
    char wyraz[i];

	for( j = 0; j < math_power_of_2(i); j++){
        wyraz[0] = '\0';
        decimal_gray = get_value(wsk, j);
        for (int x = 0; x < i; x++){

        if (decimal_gray % 2 == 0){
            strcat(wyraz,"0");
        }

            else
        {
            strcat(wyraz,"1");
        }
        decimal_gray = decimal_gray/2;
        }

        fprintf(plik, "%s", strrev(wyraz));
        fprintf(plik, "\n");
    }
	fclose(plik);
return 0;
}
