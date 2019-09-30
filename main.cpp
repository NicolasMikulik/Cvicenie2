#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100001

long sucet_k_najvacsich(int cena[], int n, int k)
{
    int eachNumber = 0, maxValue = 0;
    int *sortedInput = (int*)malloc(n*sizeof(int));
    int *appearances = (int*)calloc(MAXSIZE,sizeof(int));
    memset(appearances,MAXSIZE,0);

    while((eachNumber < n) && scanf("%d",&cena[eachNumber++]) == 1 );
    maxValue = cena[0];
    for (int eachNumber = 0; eachNumber < n; ++eachNumber) {
        ++appearances[cena[eachNumber]];
        if(cena[eachNumber] > maxValue)
            maxValue = cena[eachNumber];
    }
    //printf("Max %d\n",maxValue);
    for (int eachNumber = 1; eachNumber < 100; ++eachNumber)
        appearances[eachNumber] += appearances[eachNumber-1];

    //for (int i = 0; i < 100; ++i)
        //printf("%d \n",appearances[i]);


    for (int eachNumber = 0; eachNumber < n; ++eachNumber) {
        sortedInput[appearances[cena[eachNumber]]-1] = cena[eachNumber];
        --appearances[cena[eachNumber]];
    }

    //for (int eachNumber = 0; eachNumber < n; ++eachNumber)
        //printf("%d ", sortedInput[eachNumber]);
    long sum = 0;
    for (int eachNumber = 0; eachNumber < n; ++eachNumber){
        if(k==0)
            break;
        k--;
        sum += sortedInput[n-1-eachNumber];
    }

    //printf("\n%ld\n",sum);
    return sum;
}

int main() {
    int n = 0,eachNumber = 0, k = 0,kthNumber = 0;
    int maxValue=0;
    scanf("%d %d",&n,&k);
    int cena[n];
    long result = sucet_k_najvacsich(cena,n,k);
    /*int *input = (int*)malloc((size)*sizeof(int));
    int *sortedInput = (int*)malloc((size)*sizeof(int));
    int *appearances = (int*)calloc(MAXSIZE,sizeof(int));
    memset(appearances,MAXSIZE,0);

    while((eachNumber < n) && scanf("%d",&cena[eachNumber++]) == 1 );
    maxValue = cena[0];
    for (int eachNumber = 0; eachNumber < n; ++eachNumber) {
        ++appearances[cena[eachNumber]];
        if(cena[eachNumber] > maxValue)
            maxValue = cena[eachNumber];
    }
    printf("Max %d\n",maxValue);
    for (int eachNumber = 1; eachNumber < 100; ++eachNumber)
        appearances[eachNumber] += appearances[eachNumber-1];

    for (int i = 0; i < 100; ++i) {
        printf("%d \n",appearances[i]);
    }

    for (int eachNumber = 0; eachNumber < n; ++eachNumber) {
        sortedInput[appearances[cena[eachNumber]]-1] = cena[eachNumber];
        --appearances[cena[eachNumber]];
    }

    for (int eachNumber = 0; eachNumber < n; ++eachNumber)
        printf("%d ", sortedInput[eachNumber]);
    long sum = 0;
    for (int eachNumber = 0; eachNumber < n; ++eachNumber){
        if(k==0)
            break;
        k--;
        sum += sortedInput[n-1-eachNumber];
    }*/

    printf("\n%ld\n",result);

    return 0;
} 