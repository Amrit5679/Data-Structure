#include<stdio.h>
#include<stdlib.h>
int time=0;
struct node{
	int vertex;
	struct node *next;
};
struct node *createNode(int v);
struct graph{
	int numvertices;
	struct node **adjLists;
};
struct node* createNode(int v){
	struct node *newNode=malloc(sizeof(struct node));
	newNode->vertex=v;
	newNode->next=NULL;
	return newNode;
};

struct graph* createGraph(int vertices){
	struct graph* graph=malloc(sizeof(struct graph));
	graph->numvertices=vertices;
	graph->adjLists=malloc(vertices*sizeof(struct graph*));
	int i;
	for(i=0;i<vertices;i++){
		graph->adjLists[i]=NULL;
	}
	return graph;
}

void addEdge(struct graph* graph,int src,int dest){
	struct node * newNode=createNode(dest);

	newNode->next=graph->adjLists[src];
	graph->adjLists[src]=newNode;

	newNode=createNode(src);

	newNode->next=graph->adjLists[dest];
    graph->adjLists[dest]=newNode;
}

void printGraph(struct graph * graph){
	int v;
	for(v=0;v<graph->numvertices;v++){
		struct node * temp=graph->adjLists[v];
		printf("\n Adjancy List of a vetex %d\n", v);
		while(temp !=NULL){
			printf("%d-> ",temp->vertex);
			temp=temp->next;
		}
		printf("\n");
	}
}

int main(){
	struct graph * graph=createGraph(4);
	addEdge(graph,0,1);
	addEdge(graph,0,2);
	addEdge(graph,1,2);
	addEdge(graph,2,3);

	printGraph(graph);
	return 0;
}
