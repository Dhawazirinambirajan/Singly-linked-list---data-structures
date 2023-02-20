

#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void insert_beg();
void insert_end();
void display();

void main()
{
    int choice=0;
    while(choice!=4)
    {
        printf("\n\n1: Insertion at Beginning\n2: Insertion at End\n3: Display the List\n4: To exit\n");
        printf("Enter your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:
                printf("Exit");
               break;
            case 1:
                insert_beg();
                break;
            case 2:
                insert_end();
                break;
            case 3:
                display();
                break;
            case 4:
               printf("Exit");
               break;
            default:
                printf("Enter valid value");
                break;
        }
    }
}

void insert_beg()
{
    struct node *ptr;
    int item;
    ptr=(struct node*)malloc(sizeof(struct node*));
    if(ptr==NULL)
    {
        printf("\nOverflow");
    }
    else
    {
        printf("\nEnter the data :");
        scanf("%d",&item);
        ptr->data=item;
        ptr->next=head;
        head=ptr;
        printf("\n Node inserted");
    }
}
void insert_end()
{
    struct node*ptr,*temp;
    int item;
    ptr=(struct node*)malloc(sizeof(struct node*));
    if(ptr==NULL)
    {
        printf("\nOverflow");
    }
    else
    {
        printf("\nEnter the data:");
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL)
        {
            ptr->next=NULL;
            head=ptr;
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=NULL;
            printf("\n Node inserted");
        }
    }
}
void display()
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node*));
    ptr=head;
    if(head==NULL)
    {
        printf("\nNO node to display\n");
    }
    else
    {
        while(ptr!=NULL)
        {
         printf("\n%d",ptr->data);
         ptr=ptr->next;
        }
        printf("\nAll nodes are displayed");
    }
}
