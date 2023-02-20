#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;

void insert();
void search();
void display();

void main()
{
    int choice=0;
    while(choice!=4)
    {
        printf("\n1:Insert\n2:Search\n3:Display\n4:Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
               insert();
               break;
            case 2:
               search();
               break;
            case 3:
               display();
               break;
            case 4:
               exit(0);
               break;
            default:
               printf("\nEnter valid value");
        }
    }
}

void insert()
{
    struct node *ptr,*temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node*));
    if(ptr==NULL)
    {
        printf("\nOverflow");
    }
    else
    {
        printf("Enter the data:");
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL)
        {
            ptr->next = NULL;
            head=ptr;
            printf("\nNODE INSERTED\n");
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
            printf("\nNODE INSERTED\n");
        }
    }
}

void search()
{
    struct node *ptr;
    int i=0,item,flag=0;
    ptr=(struct node*)malloc(sizeof(struct node*));
    printf("\nEnter the data to search:");
    scanf("%d",&item);
    ptr=head;
    if(ptr==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
     while(ptr!=NULL)
     {
        if(ptr->data==item)
        {
          printf("The searched element %d is located at %d postion\n",item,i+1);
          flag=1;
        }
        else
          flag=0;
        i++;
        ptr=ptr->next;
     }
    }
    if(flag==0)
       printf("Element not found\n");
    
}

void display()
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node*));
    ptr=head;
    if(ptr==NULL)
    {
        printf("Nonodes to display\n");
    }
    else
    {
        while(ptr!=NULL)
        {
         printf("%d\n",ptr->data);
         ptr=ptr->next;
        }
    } 
}
