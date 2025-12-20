#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
    struct node * prev;    // $
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;    // $

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn -> next = *first;
        (*first) -> prev = newn;   // $
        *first = newn;
    }

}

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;    // $

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp -> next != NULL)  // Type 2
        {
            temp = temp -> next;
        }
        temp -> next = newn;
        newn -> prev = temp;   // $     temp->next->prev = temp
    }
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        *first = (*first) -> next;
        free(temp);
        (*first) -> prev = NULL;      // $

    }
}

void DeleteLast(PPNODE first)
{
    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        
    }
}

void Display(PNODE first)
{
    printf("\nNULL <=> ");
    while(first != NULL)  // Type 1
    {
        printf("| %d | <=> ", first->data);
        first = first -> next;
    }
    printf(" NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first -> next;
    }
    return iCount;
}

void InsertAtPos(PPNODE first, int no, int pos)
{

}

void DeleteAtPos(PPNODE first, int pos)
{
    
}
int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);
    iRet = Count(head);
    printf("No of nodes are : %d",iRet);

    InsertLast(&head,101);
    InsertLast(&head,102);
    InsertLast(&head,103);

    Display(head);
    iRet = Count(head);
    printf("No of nodes are : %d",iRet);

    DeleteFirst(&head);

    Display(head);
    iRet = Count(head);
    printf("No of nodes are : %d",iRet);

    return 0;
}