#include <stdio.h>
#include <stdlib.h>
void insBeg();
void insEnd();
void insLoc();
void delBeg();
void delEnd();
void delLoc();
void display();
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start;
int main()
{
    int ch;
    printf("\n\tDoubly Linked List\n\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at any location\n");
    printf("4. Delete from Beginning\n");
    printf("5. Delete from End\n");
    printf("6. Delete from any location\n");
    printf("7. Display\n");
    printf("8. EXIT\n\n");

    do
    {
        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insBeg();
            break;
        case 2:
            insEnd();
            break;
        case 3:
            insLoc();
            break;
        case 4:
            delBeg();
            break;
        case 5:
            delEnd();
            break;
        case 6:
            delLoc();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        default:
            printf("Something went wrong!! please try again");
            break;
        }
    } while (ch != 8);

    return 0;
}

void insBeg()
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    int val;
    if (ptr == NULL)
    {
        printf("\nMemory not available\n");
    }
    else
    {
        printf("\nEnter value to insert at beginning: ");
        scanf("%d", &val);
        ptr->prev = NULL;
        ptr->next = NULL;
        ptr->data = val;
        if (start == NULL)
        {
            start = ptr;
        }
        else
        {

            ptr->next = start;
            start->prev = ptr;
            start = ptr;
        }
    }
}
void insEnd()
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    int val;
    if (ptr == NULL)
    {
        printf("\nMemory not available\n");
    }
    else
    {
        printf("\nEnter value to insert at end: ");
        scanf("%d", &val);
        ptr->prev = NULL;
        ptr->next = NULL;
        ptr->data = val;
        if (start == NULL)
        {

            start = ptr;
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }
    }
}
void insLoc()
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    int val, loc;
    if (ptr == NULL)
    {
        printf("\nMemory not available\n");
    }
    else
    {
        printf("\nEnter value to insert any location: ");
        scanf("%d", &val);
        ptr->data = val;
        ptr->prev = NULL;
        ptr->next = NULL;

        printf("Enter location: ");
        scanf("%d", &loc);

        if (start == NULL)
        {
            start = ptr;
        }
        else
        {
            temp = start;
            while (temp->data != loc)
            {
                temp = temp->next;
            }
            ptr->next = temp->next;
            ptr->prev = temp;
            temp->next->prev = ptr;
            temp->next = ptr;
        }
    }
}
void delBeg()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nList is Empty\n");
    }
    else
    {
        ptr = start;
        start = start->next;
        start->prev = NULL;
        printf("Deleted data is %d from Beginning", ptr->data);
        free(ptr);
    }
}
void delEnd()
{
    struct node *temp;
    if (start == NULL)
    {
        printf("\nList is Empty\n");
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        printf("Deleted data is %d from End", temp->data);
        free(temp);
    }
}
void delLoc()
{
    struct node *temp;
    int loc;
    if (start == NULL)
    {
        printf("\nList is Empty\n");
    }
    else
    {
        printf("\nEnter location to delete: ");
        scanf("%d", &loc);
        temp = start;
        while (temp->data != loc)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        printf("Deleted data is %d", temp->data);
        free(temp);
    }
}
void display()
{
    if (start == NULL)
    {
        printf("\nList is Empty\n");
    }
    else
    {
        struct node *ptr = start;
        while (ptr != NULL)
        {
            printf("| %d |", ptr->data);
            ptr = ptr->next;
        }
    }
}