#include <stdlib.h>
#include <stdio.h>

struct Node{
    int data;
    struct Node* next;
};

void inserir(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    struct Node *last = *head_ref;

    new_node->data = new_data;

    new_node->next = NULL;

    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while(last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

void reverseList(struct Node** head_ref)
{
    struct Node* anterior = NULL;
    struct Node* atual = *head_ref;
    struct Node* prox = NULL;

    while(atual != NULL)
    {
       prox = atual->next;
       atual->next = anterior;
       anterior = atual;
       atual = prox;
    }
    *head_ref = anterior;
}

void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main(){
  //var
    struct Node* head = NULL;
    int n = 0, data = 0;
  //
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &data);
        inserir(&head, data);
    }
    reverseList(&head);
    printList(head);
  //
    printf("\n\n");
    system("pause");
    return 0;
}
