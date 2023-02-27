#include <stdio.h>
#include <string.h>
#include <time.h>

void compress (char path[]) {
    FILE *f;
    char c;
    f = fopen(path, "r");
    c = fgetc(f);

    while (c != EOF) {
        printf("%c", c);
        c = fgetc(f);
    }

    fclose(f);
}

int main () {
    clock_t startTime, endTime;
    startTime = clock();

    char filePath[] = "enwik9_sample.txt";
    compress(filePath);

    endTime = clock();
    double duration = (((double)endTime - startTime)/CLOCKS_PER_SEC) * 1000;

    printf("\n\nDuration: %f ms \n", duration);

    return 0;
}