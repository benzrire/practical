#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

typedef struct node {
    char id[MAX];
    char name[MAX];
    int qnt;
    double price;
}node;

int main()
{
    char buffer[MAX], *token;
    node data[MAX];
    int count = 0, i;
    FILE *fp;
    double total;

    while(1) {
        printf("Input:");
        fgets(buffer, MAX, stdin);
        if(strcmp(buffer, "\n") == 0) {
            break;
        }
        sscanf(buffer, "%s %d %lf", data[count].id, &data[count].qnt, &data[count].price);
        strcpy(data[count].name, " ");
        count += 1;
    }

    fp = fopen("product.txt", "r");

    while(fgets(buffer, MAX, fp)) {
        token = strtok(buffer, ","); // 101
        for(i = 0; i < count; i++) {
            if(strcmp(token, data[i].id) == 0) {
                strcpy(data[i].name, strtok(NULL, "\n"));
                break;
            }
        }
    }

    fclose(fp);

    total = 0;
    printf("Product ID   Name           Quantity     Unit price     Cost\n");
    for(i = 0; i < count; i++) {
        printf("%-13s%-15s%-13d%-15.2lf%.2lf\n", data[i].id, data[i].name, data[i].qnt, data[i].price, (data[i].qnt * data[i].price));
        total = total + (data[i].price * data[i].qnt);
    }
    printf("                                                  Total %.2lf\n", total);

    printf("Output filename:");
    fgets(buffer, MAX, stdin);
    if(strcmp(buffer, "\n") == 0) {
        printf("Output does not save.");
    } else {
        sscanf(buffer, "%s", buffer);

        fp = fopen(buffer, "w");

        fprintf(fp ,"Product ID   Name           Quantity     Unit price     Cost\n");
        for(i = 0; i < count; i++) {
            fprintf(fp, "%-13s%-15s%-13d%-15.2lf%.2lf\n", data[i].id, data[i].name, data[i].qnt, data[i].price, (data[i].qnt * data[i].price));
        }
        fprintf(fp, "                                                  Total %.2lf\n", total);

        fclose(fp);

        printf("Output saved.\n");
    }



    return 0;
}
