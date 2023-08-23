#include<stdio.h>
#include<stdlib.h>

void dijkstra(int **arr, int n) {
    int r, c, s, i, j, k;
    int *d = (int *)calloc(n, sizeof(int));
    int *p = (int *)calloc(n, sizeof(int));
    int *v = (int *)calloc(n, sizeof(int));

    for (r = 0; r < n; r++) {
        for(c = 0; c < n; c++) {
            if(arr[r][c] == 0 && r != c) {
                arr[r][c] = 999;
            }
        }
    }

    printf("Enter the source vertex: \n");
    scanf("%d", &s);

    s = s-1;
    for(i = 0; i < n; i++) {
        d[i] = arr[s][i];
        p[i] = s + 1;
        v[i] = 0;
    }
    v[s] = 1;

    for (i = 0; i < n; i++) {
        int min = 999;
        for(j = 0; j < n; j++) {
            if (v[j] == 0 && d[j] < min) {
                min = d[j];
                k = j;
            }
        }

        v[k] = 1;
        for (j = 0; j < n; j++) {
            if(v[j] == 0 && d[j] > d[k] + arr[k][j]) {
                d[j] = d[k] + arr[k][j];
                p[j] = k +1;
            }
        }
    }

    for(i = 0; i < n; i++) {
        if(i != s) {
            printf("The distance between %d and %d is: %d\n", i+1, s+1, d[i]);
            printf("Path: %d", i +1);
            j = i;
            do {
                j = p[j] - 1;
                printf("<-%d", j+1);
            } while(j != s);
            printf("\n");
        }
        

    }

    

}

int main() {
    int n, i, u, v, w, ch;
    printf("Enter the number of vertices: \n");
    fflush(stdin);
    scanf("%d", &n);
    int **arr = (int **)calloc(n, sizeof(int *));
    for(i = 0; i < n; i++) {
        arr[i] = (int *)calloc(n, sizeof(int));
    }
    do {
        printf("Enter the node pair which have edge between them:\n");
        scanf("%d%d", &u, &v);
        printf("Enter the weight of the edge:\n");
        scanf("%d", &w);
        arr[u-1][v-1] = w;
        arr[v-1][u-1] = w;
        printf("Do you want to enter more?(0/1):\n");
        scanf("%d", &ch);
    } while(ch != 0);

    dijkstra(arr, n);
    return 0;
}