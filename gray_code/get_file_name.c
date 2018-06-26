#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *get_file_name(int argc, char **argv, int n){
    for (int i = 1; i < argc; i++){
        if (i != n){
            strcat(argv[i], ".txt");
            return argv[i];
        }
    }
}



