#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256
#define FILENAME "data.txt"

int main()
{
    char buffer[MAX];
    int n, i;
    double *data, min, max, avg;
    FILE *fp;

    fp = fopen(FILENAME, "w");

    while(1) {

        fgets(buffer, MAX, stdin);
        sscanf(buffer, "%d", &n);

        if(n <= 0) {
            break;
        }

        data = (double *)malloc(n * sizeof(double));

        avg = 0;
        for(i = 0; i < n; i++) {
            fgets(buffer, MAX, stdin);
            sscanf(buffer, "%lf", &data[i]);
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

        printf("min=%.2lf max=%.2lf average=%.2lf ", min, max, avg);
        fprintf(fp, "min=%.2lf max=%.2lf average=%.2lf ", min, max, avg);
        printf("data={ ");
        fprintf(fp, "data={ ");
        for(i = 0; i < n; i++) {
            printf("%.2lf", data[i]);
            fprintf(fp, "%.2lf", data[i]);
            if(i < n - 1) {
                printf(",");
                fprintf(fp, ",");
            }
        }
        printf(" }\n");
        fprintf(fp, " }\n");
    }

    fclose(fp);


    return 0;
}
