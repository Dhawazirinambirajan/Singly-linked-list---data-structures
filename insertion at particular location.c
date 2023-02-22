#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void insert();
void insert_particular();
void display();

void main()
{
    int choice=0;
    while(choice!=4)
    {
        printf("\n1:Insert\n2:Insertion at particular Location\n3:Display the nodes\n4: To exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                  insert();
                  break;
            case 2:
                 insert_particular();
                 break;
            case 3:
                 display();
                 break;
            case 4:
                 printf("\nPROCESS TERMINATED\n");
                 break;
            default:
                 printf("\nEnter valid value\n");
                 break;
        }
    }
}

void insert()
{
    struct node *ptr,*temp;
    int item;
    ptr=(struct node*)malloc(sizeof(struct node*));
    if(ptr==NULL)
    {
        printf("\noverflow");
    }
    else
    {
        printf("Enter the data:");
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL)
        {
            ptr->next=NULL;
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
            ptr->next=NULL;
            temp->next=ptr;
            printf("\nNODE INSERTED\n");
        }
    }
}

void insert_particular()
{
    struct node *ptr,*temp;
    int item,loc,i;
    ptr=(struct node*)malloc(sizeof(struct node*));
    if(ptr==NULL)
    {
        printf("\nOverflow");
    }
    else
    {
        printf("Enter the data:");
        scanf("%d",&item);
        ptr->data=item;
        printf("\nEnter the location after you want to insert:");
        scanf("%d",&loc);
        temp=head;
        for(i=0;i<loc;i++)
        {
            temp=temp->next;
            if(temp==NULL)
            {
                printf("\nNODE CANNOT BE INSERTED AT THAT LOCATION\n");
            }
        }
        ptr->next=temp->next;
        temp->next=ptr;
        printf("\n NODE INSERTED\n");
    }
}

void display()
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node*));
    ptr=head;
    if(ptr==NULL)
    {
        printf("\n NODE NODE TO DISPLAY\n");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
    printf("\nAll nodes were displayed\n");
}






