#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int x;
	int y;
	struct node *next;
}node;
node *rear,*front;
int isEmpty()
{
	if(front==NULL)
		return 1;
	else return 0;
}
void enqueue(int x,int y)
{
	node* t;
	t=(node*)malloc(sizeof(node));
	t->x=x;
	t->y=y;
	t->next=NULL;
	if(isEmpty())
	{
		front=t;
		rear=front;
    }
    else{
            rear->next=t;
            rear=t;
            rear->next=NULL;
        }
}
void queuefront(int *x,int *y)
{
	*x=front->x;
	*y=front->y;
	return;
}
void dequeue()
{
	node* t;
	if(isEmpty())
    {
        printf("Queue Underflow\n");
        return;
    }
	t=front;
	front=t->next;
    free(t);

}
