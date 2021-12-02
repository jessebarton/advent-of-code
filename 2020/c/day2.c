#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int linecount() {
    FILE* file = fopen("inputday2", "r");
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

char* strip(char str[], char delim[]) {
	int init_size = strlen(str);

	char *ptr = strtok(str, delim);


	while(ptr != NULL)
	{
		ptr = strtok(NULL, delim);
	}

    return ptr;
}

char storelines() {
    FILE* file = fopen("inputday2", "r");
    char line[256];
    int i = 0;

    int arraySize = linecount();
    char *lines[arraySize];
    

    while ((fgets(line, sizeof(line), file)) != NULL){
        lines[i]=malloc(sizeof(line)*sizeof(char));
        strcpy(lines[i], line);
        i++;
    }

    return &lines;
}

void swap(int *pa, int *pb) {
    int t = *pa;
    *pa = *pb;
    *pb = t;
}

int main()
{
    int a = 10;
    int b = 5;
    swap(&a, &b);


    storelines();

    // for (int i=0;i<5;i++) {
    //     printf("%d", arr[i]);
    // }

    return 0;
}