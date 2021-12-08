#include <stdio.h>
#include <stdlib.h>


 #define QUEUE_CAPACITY 3
 typedef struct tag_queue
 {
 	int *pQueue;
	int head;
	int tail;
	unsigned int length;
 }LineQueue;
int InitQueue(LineQueue **myQueue);
 int QueueFull(LineQueue *myQueue);
int EnQueue(LineQueue *myQueue,int element);
 int InitQueue(LineQueue **myQueue)
 {
 	(*myQueue)= (LineQueue *)malloc(sizeof(LineQueue));
	 printf("%p\n",*myQueue);
	if(myQueue == NULL)
	{
		return 0;
	}
	(*myQueue)->pQueue = (int *)malloc(sizeof(int)*QUEUE_CAPACITY);
	if((*myQueue)-> pQueue == NULL)
	{
		return 0;
	}
		(*myQueue)->head=0;
		(*myQueue)->tail=0;
		(*myQueue)->length=0;
		return 1;
	

 }

int QueueFull(LineQueue *myQueue)
{
	if(myQueue->length == 0)
	{
		return 1;
	}
	return 0;
}
 int EnQueue(LineQueue *myQueue,int element)
 {
 	if(QueueFull(myQueue))
	{
		return 0;
	}
	myQueue->pQueue[myQueue->tail]= element;
        myQueue->tail++;
	myQueue->length++;
	return 1;


 }

 int QueueTraverse(LineQueue *myQueue,int flag)
 {
 	int i=0;
	if(flag ==0)
	{
		for(i=0;i<myQueue->length;i++)
		{
			printf("%d",myQueue->pQueue[i]);
		}
	}
	if(flag ==1)
	{
		for(i=myQueue->length-1;i >= 0; i--)
		{
			printf("%d",myQueue->pQueue[i]);
		}
	
	}

 }

 int main(void)
 {
 	int elem=0;
	LineQueue *queue = NULL;
	InitQueue(&queue);
	printf("%p\n",queue);
        EnQueue(queue,2);
	EnQueue(queue,3);
	QueueTraverse(queue,0);
	return 0;
 }

