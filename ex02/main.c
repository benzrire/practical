#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 256

int main()
{
    char buffer[MAX];
    int i, n, *data, min, max;
    double avg;
    FILE *fp;

    // important!!!!
    srand(time(NULL));

    while(1) {
        printf("Input n[1-100]:");
        fgets(buffer, MAX, stdin);
        sscanf(buffer, "%d", &n);
        if(n >= 1 && n <= 100) {
            break;
        }
    }

    data = (int *)malloc(n * sizeof(int));

    avg = 0;
    for(i = 0; i < n; i++) {
        // rand() %range +minimum
        data[i] = rand() %100 +1;

        // initial
        if(i == 0) {
            min = max = data[i];
        }
        if(data[i] < min) {
            min = data[i];
        }
        if(data[i] > max) {
            max = data[i];
        }
        avg = avg + data[i];
    }
    avg = avg / (double)n;

    for(i = 0; i < n; i++) {
        printf("%d) %d\n", i, data[i]);
    }
    printf("Min = %d Max = %d average =%.2lf\n", min, max, avg);

    printf("Input a filename:");
    fgets(buffer, MAX, stdin); // data.txt\n
    sscanf(buffer, "%s", buffer); // data.txt
    // buffer[strlen(buffer) - 1] = '\0'; // data.txt

    fp = fopen(buffer, "w");
    for(i = 0; i < n; i++) {
        fprintf(fp, "%d ", data[i]);
    }
    fprintf(fp, "\nMin = %d Max = %d average =%.2lf\n", min, max, avg);
    fclose(fp);

    return 0;
}
