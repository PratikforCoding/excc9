#include<stdio.h>
#include<stdlib.h>

void prims(int **arr, int n) {
    int i, count, minkey,v;
    int *p = (int *)calloc(n, sizeof(int));
    int *key = (int *)calloc(n, sizeof(int));
    int *mst = (int *)calloc(n, sizeof(int));

    for(i = 0; i < n; i++) {
        mst[i]=0;
        key[i]=999;
    }

    key[0] = 0;
    p[0] = -1;

    for(count = 0; count < n -1; count++) {
        int u; minkey = 999;
        for(v = 0; v < n; v++) {
            if(mst[v]== 0 && key[v] < minkey) {
                minkey = key[v];
                u = v;
            }
        }
        mst[u] = 1;
        for(v = 0; v < n; v++) {
            if (arr[u][v] && mst[v] == 0 && arr[u][v] < key[v]) {
                p[v] = u;
                key[v] = arr[u][v];
            }
        }
    }

    printf("The minimum spanning tree: \n");
    for(i = 1; i < n; i++) {
        printf("%d <--> %d  %d\n", p[i]+1, i+1, arr[i][p[i]]);
    }

}
int main() {
    int n, u, v, i, ch, w;
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);
    int **arr = (int **)calloc(n, sizeof(int *));
    for(i = 0; i < n; i ++) {
        arr[i] = (int *)calloc(n, sizeof(int));
    }
    do {
        printf("Enter the nodes which have edge between them:\n");
        scanf("%d%d", &u, &v);
        printf("Enter the edge weight: \n");
        scanf("%d", &w);
        arr[u-1][v-1] = w;
        arr[v-1][u-1] = w;
        printf("Do you want to Enter more(0/1):\n");
        scanf("%d", &ch);
    } while (ch != 0);

    printf("The matrix is: \n");
    for(u=0; u< n; u++) {
        for(v = 0; v < n;v++) {
            printf("%5d", arr[u][v]);
        }
        printf("\n");
    }

    prims(arr, n);
    return 0;

}