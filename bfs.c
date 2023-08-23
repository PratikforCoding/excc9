#include<stdio.h>
#include<stdlib.h>

void bfs(int **arr, int n, int s) {

    int i, front=-1, rear=-1, u,count=0,v,d,t,k;
	
	int *dis=(int *)calloc(n, sizeof(int));
	int *par=(int *)calloc(n, sizeof(int));
	int *queue=(int *)calloc(n, sizeof(int));
	
	for(i=0;i<n;i++)
	{
		dis[i]=-1;
		par[i]=-1;
	}
	dis[s-1]=0;
	printf("s=%d\n",s);
	
	queue[++rear]=s;
	
	printf("The traversal is:\n");
	while(front != rear)
	{
		u=queue[++front]-1;
		printf("%c\t", (u+1+64));
		count++;
		for(v=0;v<n;v++)
		{
			if(arr[u][v]==1)
			{
				if(dis[v]<0)
				{
					dis[v]=dis[u]+1;
					par[v]=u+1;
					queue[++rear]=v+1;
				}
			}
		}
	}

    for(k=n;k>=1;k--){
		t=k;
		printf("\nThe path from node %c to %c node: \n",(t+64),(s+64));
		printf("%c",(t+64));
		while(par[t-1]!=-1){
			t=par[t-1];
			printf("->%c",(t+65));
		}
	}
	printf("\n");
}

void dfs(int **arr, int n, int s) {
    int i,u,v,top=-1,t,k,count=0;
    int *dis = (int *)calloc(n, sizeof(int));
    int *par = (int *)calloc(n, sizeof(int));
    int *stack = (int *)calloc(n, sizeof(int));

    for ( i = 0; i < n; i++)
    {
        /* code */
        dis[i] = -1;
        par[i] = -1;
    }
    printf("The source is : %d\n",s);
    dis[s-0] = 0;
    stack[++top] = s;

    while(top != -1) {
        u = stack[top--] - 1;
        printf("The traversal is: \n");
        printf("%d\t", u);
        count++;
        for(v = 0; v < n; v++) {
            if (dis[v] <= 0) {
                dis[v] = dis[u] + 1;
                par[v] = u+1;
                stack[++top] = v + 1;
            }
        }
    }
    for(k=n; k>=1; k--) {
        t = k;
        printf("The path from node %d to node %d is: ", t, s);
        printf("%d", t);
        while(par[t -1] != -1) {
            t = par[t-1];
            printf("->%d", t);
        }
    }
    
}

int main() {
    int n,i,j,ch,u,v,option, s;
    do {
        printf("Enter the number of vertices: \n");
        scanf("%d", &n);
    } while(n <= 0);

    int **arr = (int **)calloc(n, sizeof(int *));

    for(i = 0; i < n; i++) {
        arr[i] = (int *)calloc(n, sizeof(int));
    }

    do {
        printf("Enter the index of node pair which have edge between them");
        scanf("%d%d", &u, &v);
        arr[u-1][v-1] = 1;
        arr[v-1][u-1] = 1;
        printf("Do you want to enter more?(0/1)");
        scanf("%d", &ch);
    } while(ch != 0);

    printf("The matrix is : \n");
    for(u = 0; u < n; u++) {
        for(v = 0; v < n; v++) {
            printf("%d", arr[u][v]);
        }
        printf("\n");
    }

    do {

        printf("\nEnter your choice:\n1: BFS\n2: DFS\n3: Exit\n");
        do {
            printf("Enter your choice: \n");
            scanf("%d", &option);
        } while(option != 1 && option != 2  && option!= 3);

        switch(option) {
            case 1: 
            printf("Enter starting vertex: \n");
            scanf("%d", &s);
            bfs(arr, n, s);
            break;
            case 2: 
            printf("Enter starting vertex: \n");
            scanf("%d", &s);
            dfs(arr, n, s);
            break;
            case 3:
            exit(0);
            break;
            default: 
            printf("Invalid input.");
            break;
        }
    }while(option != 3);
    return 0;
}