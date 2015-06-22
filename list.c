#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node Node;

Node *head;
Node *tail;

void insert(int);
int fetch(int);
int display();
int main(int argc, char *argv[])
{
    int choice;
    int value;
    int index;
    while(1)
    {
        printf("What do you want to do?\n\n");
        printf("1. Insert \n2. Fetch \n3. Display \n4. Exit \n");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("\nEnter the value you want to insert!\n");
            scanf("%d", &value);
            insert(value);
            printf("\nInserted the value %d into linkedList\n", value);
            break;
        case 2:
            printf("\nValue at what index you want to fetch\n");
            scanf("%d", &index);
            value = fetch(index);
            printf("\nValue at index %d is %d\n", index, value); //need to fetch real value
            break;
        case 3:
            printf("\nContent in the List.....\n");
            display();
            break;
        case 4:
            return 0;
            break;
        default:
            break;
        }
    }
}


void insert(int value)
{
    if(head == NULL)
    {
        head = (Node *)malloc(sizeof(Node));
        head->value = value;
        head->next = NULL;
        tail = head;
    }
    else
    {
        tail->next = (Node *)malloc(sizeof(Node));
        tail->next->value = value;
        tail->next->next = NULL;
        tail = tail->next;
    }
}

int fetch(int index)
{
    int i;
    if(head == NULL)
    {
        return -1;
    }

    Node *pointer = head;
    for (i = 0; i < index; i++)
    {
        if(pointer->next == NULL)
        {
            return -1;
        }
        pointer = pointer->next;
    }

    return pointer->value;

}
int display()
{
    Node *a;
    a=head;
    while(a!=tail)
    {
        printf("%d ",a->value);
        a=a->next;
    }
    if(a==tail)
    {
        printf("%d\n",a->value);
    }
    return 0;
}
