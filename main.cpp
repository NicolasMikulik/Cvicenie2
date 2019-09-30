#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100001



int main() {
    int size = 0,eachNumber = 0, wish = 0,kthNumber = 0;
    int maxValue=0;
    scanf("%d %d",&size,&wish);
    int *input = (int*)malloc((size)*sizeof(int));
    int *sortedInput = (int*)malloc((size)*sizeof(int));
    int *appearances = (int*)calloc(MAXSIZE,sizeof(int));
    memset(appearances,MAXSIZE,0);

    while((eachNumber < size) && scanf("%d",&input[eachNumber++]) == 1 );
    maxValue = input[0];
    for (int eachNumber = 0; eachNumber < size; ++eachNumber) {
        ++appearances[input[eachNumber]];
        if(input[eachNumber] > maxValue)
            maxValue = input[eachNumber];
    }
    printf("Max %d\n",maxValue);
    for (int eachNumber = 1; eachNumber < 100; ++eachNumber)
        appearances[eachNumber] += appearances[eachNumber-1];

    for (int i = 0; i < 100; ++i) {
        printf("%d \n",appearances[i]);
    }

    for (int eachNumber = 0; eachNumber < size; ++eachNumber) {
        sortedInput[appearances[input[eachNumber]]-1] = input[eachNumber];
        --appearances[input[eachNumber]];
    }

    for (int eachNumber = 0; eachNumber < size; ++eachNumber)
        printf("%d ", sortedInput[eachNumber]);
    long sum = 0;
    for (int eachNumber = 0; eachNumber < size; ++eachNumber){
        if(wish==0)
            break;
        wish--;
        sum += sortedInput[size-1-eachNumber];
    }

    printf("\n%ld\n",sum);

    return 0;
} 