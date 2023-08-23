#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, u, v, e, n2, i,ch;
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);
    printf("Enter the number of edges:\n");
    scanf("%d", &n2);
    int **arr = (int **)calloc(n, sizeof(int *));
    for (i = 0; i < n; i++) {
        arr[i] = (int *)calloc(n2, sizeof(int));
    }
    do {
        printf("Enter the source and destination vertex numbers and edge number: \n");
        scanf("%d%d%d", &u, &v, &e);
        arr[u - 1][e - 1] = 1;
        arr[v - 1][e - 1] = 1;
        printf("Do you want to enter more? (0/1)");
        scanf("%d", &ch);
    } while(ch != 0);

    printf("The matrix is: \n");
    for(u = 0; u < n; u++) {
        for(e = 0; e < n2; e++) {
            printf("%d", arr[u][e]);
        }
        printf("\n");
    }
    return 0;
}