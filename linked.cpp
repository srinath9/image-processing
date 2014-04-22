#include "stdlib.h"
#include "stdio.h"

typedef struct link
{
	int k;
	struct link *next;
}link;

link* add(link* num, int i){
	link* temp;
	int q = num->k;
	temp = (link *)malloc(sizeof(link));
	//temp = num;
	temp->k = i;
	
	temp->next = num;
	return temp;
	q= temp->next->k;
	num=temp;
	q=num->k;
	return num;
}
link* remove(link* node){
	link* temp;
	int i;
	temp = (link *)malloc(sizeof(link));
	temp = node;

	while(temp->next->next!=NULL){
		temp = temp->next;

	}
	i = temp->k;
	printf("removed number is :%d\n",i );
	temp->next = NULL;


	return node;
}
link* display(link* arr){
	int i;
	link* temp;
	i = arr->k;
	printf("display = %d\n",i );
	temp = arr;
	while(temp->next->next!= NULL){
		
		temp = temp->next;
		i =temp->k;		
		printf("display = %d\n",i );
	}
	return 0;
}

int main(){
	link* list;
	int i,j,m;
	list =(link *)malloc(sizeof(link));
	list->k =10;
	i = list->k;
	list->next =NULL;
	printf("%d\n",i );
	printf("give the number of values:\n");
	scanf("%d",&i);
	for (int j = 0; j < i; ++j)
	{
		printf("enter the number\n");
		scanf("%d",&m);
		list=add(list,m);
	}
	display(list);

	for (int j = 0; j < i; ++j)
	{
		remove(list);
	}
	return 0;

}