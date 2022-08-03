#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

void usage() {
    printf("writer [STRING] [FILE_PATH]\n");
    printf("Writes STRING to FILE_PATH\n");
    printf("max string size = 30 characters\n");
}

int main(int argc, char *argv[]) 
{
    // Logging
    openlog(argv[0], LOG_CONS, LOG_USER);

    if (argc > 3) {
        syslog(LOG_ERR, "Too many arguments\n");
        usage();
        exit(1);
    } else if (argc < 3) {
        syslog(LOG_ERR, "Too few arguments\n");
        usage();
        exit(1);
    } 
    
    // Variables for parameters
    char string[30];
    char file_path[40];
    strcpy(file_path, argv[1]);
    strcpy(string, argv[2]);

    // For output file
    FILE *file_pointer;

    file_pointer = fopen(file_path, "w");
    if (file_pointer == NULL) {
        syslog(LOG_ERR, "Can't open file to write to.\n");
        printf("Can't open file to write to.\n");
        exit(1);
    }

    fprintf(file_pointer, "%s", string);
    syslog(LOG_DEBUG, "Writing %s to %s", string, file_path);
    printf("Writing %s to %s", string, file_path);

    closelog();
    fclose(file_pointer);

    return 0;
}
