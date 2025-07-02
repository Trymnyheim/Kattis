// https://open.kattis.com/problems/internationaldates

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * findZone(int date1, int date2);

int main() {
    char *buffer = (char *)malloc(10);
    if (buffer == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        return -1;
    }
    char *num = (char *)malloc(3);
    if (num == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        free(buffer);
        return -1;
    }

    if (fgets(buffer, 10, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        free(buffer);
        free(num);
        return -1;
    }

    strncpy(num, buffer, 2);
    num[2] = '\0';
    int date1 = atoi(num);
    strncpy(num, buffer + 3, 2);
    num[2] = '\0';
    int date2 = atoi(num);

    printf("%s\n", findZone(date1, date2));

    free(buffer);
    free(num);
    return 0;
}

char * findZone(int date1, int date2) {
    if (date1 > 12) {
        return "EU";
    }
    if (date2 > 12) {
        return "US";
    }
    return "either";
}

