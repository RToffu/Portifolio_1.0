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

void inserirEm(struct Node** head_ref, int new_data, int pos)
{
   int i = 0;
   struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

   struct Node *last = *head_ref;

   new_node->data = new_data;


   for(i = 0; i < pos-1; i++)
        last = last->next;
    new_node->next = last->next;
    last->next = new_node;

}

void printList(struct Node *node)
{
    while(node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}



//DRIVER_FUNCTION(main)
int main(){
  //var
    struct Node* head = NULL;
    int n = 0;
    int num = 0;
    int data = 0, pos = 0;
  //
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        inserir(&head, num);
    }
  //
    scanf("%d", &data);
    scanf("%d", &pos);
    inserirEm(&head, data, pos);
    printList(head);
  //

    printf("\n\n");
    system("pause");
    return 0;
}//END_MAIN
