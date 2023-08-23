#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node1 {
    int info;
    struct node1 *link;
    struct node *next;
};

typedef struct node subver;
typedef struct node1 mainver;

mainver *insert_sub(mainver *head , int data){
    subver *temp;
    subver *newp;
    newp = (subver *)malloc(sizeof(subver));
    newp->info = data;
    newp->next = NULL;

        if(head->next == NULL) {
            head->next = newp;
        } else {
            temp = head->next;
            while(temp->next != NULL) {
                temp = temp->next;
            }
        }
        
        temp->next = newp;
        
    return head;
}

mainver *create_sub(mainver *head) {
    int n, i, data;
    printf("How many vertices are connected with the main vertex?\n");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter the subvertex number that is connected: \n");
        scanf("%d", &data);
        head = insert_sub(head, data);
    }
    return head;
}
mainver *insert_main(mainver *head, int data) {
    mainver *temp;
    mainver *newp;
    newp = (mainver *)malloc(sizeof(mainver));
    newp->info = data;
    newp->link = NULL;
    newp->next = NULL;
    if (head == NULL) {
        head = newp;
    } else {
        temp = head;
        while(temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newp;
    }
    return head;
}

mainver *create_main(mainver *head) {
    int n, data, i;
    printf("How many main vertex do you want to enter?\n");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter the vertex that is connected to main vertex: \n");
        scanf("%d", &data);
        head = insert_main(head, data);
    }
    return head;
}

mainver *display(mainver *head) {
    mainver *temp = head;
    while(temp != NULL) {
        printf("%d: ", temp->info);
        subver *temp1 = temp->next;
        while(temp1 != NULL) {
            printf("%d", temp1->info);
            if(temp1->next != NULL) {
                printf("->");
            }
            temp1 = temp1->next;
        }
        printf("\n");
        temp = temp->link;
    }
    return head;
}

int main() {
    int n,i;
    mainver *temp = NULL;
    mainver *head = NULL; 
    head = create_main(head);
    temp = head;
    while (temp != NULL) {
        temp = create_sub(temp);
        temp = temp->link;
    }
    display(head);
    return 0;

}