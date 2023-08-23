#include<stdio.h>
#include<stdlib.h>

void floydwarshall(int **arr,int n)
{
    int i,j,k;
    int **finalArr = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        finalArr[i] = (int *)calloc(n, sizeof(int));
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            finalArr[i][j] = arr[i][j];
            
        }
    }

    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if(finalArr[i][j] == 0 && i != j) {
          finalArr[i][j] = 999; // Infinity (999)
        }
      }
    } 

    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {	
                if(finalArr[i][j] > finalArr[i][k] + finalArr[k][j]) {
                    finalArr[i][j] = finalArr[i][k] + finalArr[k][j];
                }
            }
        }
    }
    
    printf("The matrix is: \n");
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if(finalArr[i][j] == 999) {
          printf("INF");
        } else {
          printf("%4d ", finalArr[i][j]); 
        }
      }
      printf("\n");
    }
}

void warshall(int **arr, int n) {
    int i,j,k;
    int **final = (int **)calloc(n, sizeof(int *));
    for(i = 0; i < n; i++) {
        final[i] = (int *)calloc(n, sizeof(int));
    }
    for(i = 0;i < n; i++) {
        for(j = 0; j < n; j++) {
            final[i][j] = arr[i][j];
        }
    }
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                final[i][j] = arr[i][j] || (final[i][k] && final[k][j]);
            }
        }
    }
}
int main() {
    int n, i, u, v, w, ch, option;
    printf("Enter the number of vertices: \n");
    scanf("%d", &n);
    int **arr = (int **)calloc(n, sizeof(int *));

    for(i = 0; i < n; i++) {
        arr[i] = (int *)calloc(n, sizeof(int));
    }
    do {
        printf("Enter the node pair which have edge between them");
        scanf("%d%d", &u, &v);
        printf("Enter the edge weight: \n");
        scanf("%d", &w);
        arr[u-1][v-1] = w;
        arr[v-1][u-1] = w;
        printf("Do you want to enter more?(0/1):\n");
        scanf("%d", &ch);
    } while(ch != 0);

    printf("The matrix is: ");
    for(u=0; u<n; u++) {
        for(v=0;v<n;v++) {
            printf("%d", arr[u][v]);
        }
        printf("\n");
    }

    do {
        printf("\nEnter your choice:\n1:Floyd Warshall\n2:Warshall\n3:Exit");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        floydwarshall(arr, n);
        break;
        case 2:
        warshall(arr, n);
        break;
        case 3:
        exit(0);
        break;
        default:
        printf("Invalid input\n");
            break;
        }
    } while(option != 3);
    return 0;

    

}