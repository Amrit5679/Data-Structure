#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1;
struct vertex{
	int color;
	int dist;
        int par;
};
struct vertex u[8];
int n=8;
int queue[8];

/*void display(){
        int i;
       	if(front>rear){
        printf("Queue is Empty..\n");
       	}
	for(i=front;i<=rear;i++){
              printf("%d  ",queue[i]);
      	}
}*/

void enqueue(int item){
	if(front==-1){
		front=0;
	}
	queue[++rear]=item;
}

int dequeue(){
	if(front>rear || front==-1){
               front=-1,rear=-1;
	       return -1;
	}
	return(queue[front++]);  
}

void BFS(int g[][8],int s){
	int i,m;
	for(i=0;i<=8;i++){
		u[i].color='W';
		u[i].dist=0;
		u[i].par=-1;
	}
	u[s].color='G';
	u[s].dist=0;
	u[s].par=-1;
	enqueue(s);
	while(front<=rear){
	        m=dequeue();
		for(i=0;i<n;i++){
			if(g[m][i]==1){
			       	if(u[i].color=='W'){
			              u[i].color='G';
			              u[i].dist=u[m].dist+1;
				      u[i].par=m;
				      enqueue(i);
				}
			}

		}
		u[m].color='B';
		printf("%d\n",m);
	}
}
void main(){       
	int s,i;
        int g[8][8]={
		{0,1,0,0,1,0,0,0},
		{1,0,0,0,0,1,0,0},
		{0,0,0,1,0,1,0,0},
		{0,0,1,0,0,0,1,1},
		{1,0,0,0,0,0,0,0},
		{0,1,1,0,0,0,1,0},
		{0,0,0,1,0,1,0,1},
		{0,0,0,1,0,0,1,0}
		
	};
	printf("Enter the source vertex: ");
	scanf("%d",&s);
	BFS(g,s);
	printf("Enter the destination vertex:");
	scanf("%d",&i);
	printf("Distance from source: %d\n",u[i].dist);
}

