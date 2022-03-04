#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
 int data;
 struct Node *link;
};
typedef struct Node Node;
Node *getnode();
main()
{
Node *first;
 int choice,item,pos,n;
 InitializeLList(&first);
 printf("\nCreating a Singly LL\n");
 printf("\nHow many nodes to create:");
 scanf("%d",&n);
 LListcreate(&first,n);

while(1)
{
 printf("\n\n\tImplementation of SLL\n");
 printf("\n\t1.Insertion at first node");
 printf("\n\t2.Insertion at last node");
 printf("\n\t3.Insertion of node at specific location");
 printf("\n\t4.Deletion at first node");
 printf("\n\t5.Deletion at last node");
 printf("\n\t6.Deletion at any node");
 printf("\n\t7.DISPLAY");
 printf("\n\t0.Exit");
 printf("\n\tEnter choice 1/2/3/4/5/6/7");
 scanf("%d",&choice);
  switch(choice)
  {
  case 1:
  printf("\nEnter the item:");
  scanf("%d",&item);
InsertLListFirst(&first,item);
  break;
  case 2:
  printf("\nEnter the item:");
  scanf("%d",&item);
InsertLListLast(&first,item);
  break;
  case 3:
  printf("\nEnter the item:");
  scanf("%d",&item);
  printf("\nEnter node to insert:");
  scanf("%d",&pos);
InsertLListAtAny(&first,item,pos);
  break;
  case 4:
DeleteLListFirst(&first);
  break;
  case 5:
DeleteLListLast(&first);
  break;
  case 6:
  printf("\nEnter node to be deleted:");
  scanf("%d",&pos);
DeleteLListAny(&first,pos);
  break;
  case 7:
TraverseLList(first);
  break;
  case 0:
  exit(0);
  case 8:
  default:printf("\nInvalid choice");
  }
 }
}
InitializeLList(Node **first)
   {
    (*first)=NULL;
   }
LListcreate(Node **f,int n)
{
   Node *temp,*current;
   int i,item;
   for(i=1;i<=n;i++)
    {
    printf("Enter the datafield of node #%d",i);
    scanf("%d",&item);
    temp=getnode();
    temp->data=item;
    temp->link=NULL;
    if(*f==NULL)
    *f=temp;
    else
    current->link=temp;
    current=temp;
    }
 }
TraverseLList(Node *first)
 {
 printf("\nStart->");
 while(first!=NULL)
  {
  printf("%d->",first->data);
  first=first->link;
  }
  printf("end\n");
 }
InsertLListFirst(Node **first,int item)
 {
 Node *temp,*current;
 temp=getnode();
 if(temp==NULL)
  {
  printf("\nUnable to create a new node.");
  return;
  }
  temp->data=item;
  temp->link=(*first);
  (*first)=temp;
 }
InsertLListLast(Node **first,int item)
 {
 Node *temp,*current;
 temp=getnode();
 if(temp==NULL)
  {
  printf("\nUnable to create a new node.");
  return;
  }
  temp->data=item;
  temp->link=NULL;
   if(*first==NULL)
      (*first)=temp;
   else
   {
     current=(*first);
     while(current->link!=NULL)
       current=current->link;
       current->link=temp;
    }
   }
InsertLListAtAny(Node **first,int item,int pos)
     {
     Node *current,*previous,*temp;
     int i;
     temp=getnode();
      if(temp==NULL)
      {
      printf("\nUnable to create a new node.");
      return;
      }
       if((*first==NULL)||(pos==1))
	 {
	 temp->data=item;
	 temp->link=(*first);
	  (*first)=temp;
	  return;
	  }
	    current=(*first)->link;
	    previous=(*first);
	    i=1;
	    while(current!=NULL)
	    {
	      if((i+1)==pos)
	       break;
	      else
	       {
	       previous=current;
	       current=current->link;
	       i++;
	       }
	     }
	     temp->data=item;
	     temp->link=current;
	     previous->link=temp;
	     }
	     DeleteLListFirst(Node **first)
	      {
	      Node * current;
	      int item;
	      if(*first==NULL)
		{
	       printf("\nList is empty");
	       return;
		}
	       current=(*first);
	       item=current->data;
	       (*first)=(*first)->link;
	       free(current);
	       printf("\nDeleted item=%d",item);
	     }
 DeleteLListLast(Node **first)
	      {
	      Node *current,*previous;
	      int item;
	      if(*first==NULL)
	       {
	       printf("\t\nList is empty..");
	       return;
	       }
		 current=(*first);
		 previous=NULL;
		  if((*first)->link==NULL)
		    (*first)=(*first)->link;
		  else
		   {
		   while(current->link!=NULL)
		     {
		     previous=current;
		     current=current->link;
		     }
		     previous->link=current->link;
		    }
		   item=current->data;
		   free(current);
		   printf("\nDeleted item=%d",item);
		 }
   DeleteLListAny(Node **first,int pos)
		   {
		   Node *current,*previous;
		   int item,i;
		    if(*first==NULL)
		     {
		     printf("\nList is Empty");
		     return;
		     }
		      if(pos==1)
		      {
		       current=(*first);
		       item=current->data;
		       (*first)=(*first)->link;
		       free(current);
		       printf("\nDeleted item=%d",item);
		       return;
		      }
		      current=(*first)->link;
		      previous=(*first);
		      i=2;
		       while(current!=NULL)
		       {
		       if(i==pos)
			{
			previous->link=current->link;
			item=current->data;
			free(current);
			printf("\nDeleted item=%d",item);
			}
		       else
			 {
			 previous=current;
			 current=current->link;
			 }
			i++;
		       }
		      }
		      Node *getnode()
		       {
		       Node *p;
		       p=(Node *)malloc(sizeof(Node));
		       return(p);
		      }


