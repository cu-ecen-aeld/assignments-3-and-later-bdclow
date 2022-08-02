#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage() {
    printf("writer [STRING] [FILE_PATH]\n");
    printf("Writes STRING to FILE_PATH\n");
    printf("max string size = 30 characters\n");
}

int main(int argc, char *argv[]) 
{
    if (argc > 3) {
        printf("Too many arguments\n");
        usage();
        exit(1);
    } else if (argc < 3) {
        printf("Too few arguments\n");
        usage();
        exit(1);
    } 
    
    char string[30];
    strcpy(string, argv[1]);
    char file_path[40];
    strcpy(file_path, argv[2]);

    FILE *file_pointer;
    char ch;

    file_pointer = fopen(file_path, "w");
    if (file_pointer == NULL) {
        printf("Can't open file to write to.\n");
        exit(1);
    }

    fprintf(file_pointer, "%s", string);

    fclose(file_pointer);

    return 0;
}
