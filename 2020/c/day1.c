#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strip(char *s) {
    char *p2 = s;
    while(*s != '\0') {
        if(*s != '\t' && *s != '\n') {
            *p2++ = *s++;
        } else {
            ++s;
        }
    }
    *p2 = '\0';
}

int linecount() {
    FILE* file = fopen("input", "r");
    char line[256];
    char ch;

    int linecount = 0;

    while((ch=fgetc(file))!=EOF) {
        if(ch=='\n')
            linecount++;
    }

    fclose(file);

    return linecount;
}


int main() {
    FILE* file = fopen("inputday1", "r");
    char line[256];
    char ch;
    int lc = linecount();
    int linecount = 0;
    int numbers[lc];
    int product;

    while ((fgets(line, sizeof(line), file)) != NULL) {
        strip(line);
        numbers[linecount] = atoi(line);
        linecount++;
    }

    for (int n = 0; n < lc; n++) {
        for (int nn = 0; nn < lc; nn++) {
            for (int nnn = 0; nnn < lc; nnn++) {
                int sum = numbers[n] + numbers[nn] + numbers[nnn];
                if (sum == 2020) {
                    printf("Sum: %d -- Num1: %d -- Num2: %d\n", sum, numbers[n], numbers[nn]);
                    product = numbers[n] * numbers[nn] * numbers[nnn];
                }
            }
        }
    }
    printf("Product: %d\n", product);

    fclose(file);

    return 0;
}