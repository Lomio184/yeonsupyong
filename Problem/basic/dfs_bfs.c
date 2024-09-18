#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 40

typedef struct Queue
{
    int items[SIZE];
    int front ;
    int rear ;
} Q ;

Q* createQueue() 
{
    Q* queue = malloc(sizeof(Q));
    queue->front = -1 ;
    queue->rear = -1 ;

    return queue ;
}

bool isEmpty( Q* queue )
{
    if ( queue->rear == -1 )
    {
        return true ;
    }

    return false ;
}

void enqueue( Q* queue, int value )
{
    if ( queue->rear == SIZE - 1)
    {
        printf("Queue is full\n");
        return ;
    }
    else
    {
        if ( queue->front == -1 )
        {
            queue->front = 0 ;
        }
        queue->rear++ ;
        queue->items[queue->rear] = value ;

        return ;
    }
}

int dequeue( Q* queue )
{
    if ( isEmpty(queue) == true )
    {
        printf("Queue is Empty\n") ;
        return -1 ;
    }
    else
    {
        int item = queue->items[queue->front] ;
        queue->front++;

        if ( queue->front > queue->rear )
        {
            queue->front = queue->rear  = -1;
        }

        return item;
    }
}

typedef struct Node
{
    int vertex ;
    struct Node* next;
} Node ;

typedef struct Graph
{
    int numVertices ;
    Node** adjLists;
    int* visited ;
} Graph ;

struct Node* createNode( int v )
{
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v ;
    newNode->next = NULL ;

    return newNode;
}

struct Graph* createGraph( int vertices )
{
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices ;
    graph->adjLists = malloc(vertices * sizeof(Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for ( int idx = 0 ; idx < vertices ; ++idx )
    {
        graph->adjLists[idx] = NULL ;
        graph->visited[idx]  = 0 ;
    }

    return graph;
}

void addEdge( Graph* graph, int src, int dest )
{
    Node* newNode = createNode( dest ) ;
    newNode->next = graph->adjLists[src] ;
    graph->adjLists[src] = newNode ;

    newNode = createNode( src );
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode ;

    return ;
}

void dfs( Graph* graph, int vertex )
{
    Node* adjList = graph->adjLists[vertex];
    Node* temp = adjList ;

    graph->visited[vertex] = 1;
    printf("Visited : %d\n", vertex) ;

    while ( temp != NULL )
    {
        int conVertex = temp->vertex ;

        if ( graph->visited[conVertex] == 0 )
        {
            dfs( graph, conVertex ) ;
        }

        temp = temp->next ;
    }
}

void bfs( Graph* graph, int startVertex )
{
    Q* queue = createQueue() ;

    graph->visited[startVertex] = 1 ;
    enqueue( queue, startVertex ) ;

    while ( false == isEmpty(queue) ) 
    {
        int currentVertex = dequeue(queue) ;

        printf("Visited : %d\n", currentVertex );

        Node* temp = graph->adjLists[currentVertex];

        while ( temp != NULL )
        {
            int adjVertex = temp->vertex ;

            if ( graph->visited[adjVertex] == 0 )
            {
                graph->visited[adjVertex] = 1 ;
                enqueue( queue, adjVertex );
            }

            temp = temp->next ; 
        }
    }
}

int main() {
    struct Graph* graph = createGraph(6);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);

    printf("DFS:\n");
    dfs(graph, 0);

    // 그래프를 다시 사용하려면 visited 배열을 초기화해야 합니다.
    for (int i = 0; i < 6; i++) {
        graph->visited[i] = 0;
    }

    printf("\nBFS:\n");
    bfs(graph, 0);

    return 0;
}