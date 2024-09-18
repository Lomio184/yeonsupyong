#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;
int parent[MAX];  // 경로 추적을 위한 부모 배열

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isQueueEmpty() {
    return front == -1 || front > rear;
}

// 경로를 역추적하여 출력하는 함수
void printPath(int parent[], int start, int goal) {
    if (goal == start) {
        printf("%d ", start);
    } else if (parent[goal] == -1) {
        printf("경로가 존재하지 않습니다.\n");
    } else {
        printPath(parent, start, parent[goal]);
        printf("%d ", goal);
    }
}

void bfs(int graph[][MAX], int start, int goal, int n) {
    int visited[MAX] = {0};
    
    // 시작 지점 설정
    enqueue(start);
    visited[start] = 1;
    parent[start] = -1;  // 출발 노드는 부모가 없음

    while (!isQueueEmpty()) {
        int node = dequeue();
        
        if (node == goal) {
            printf("최단 경로: ");
            printPath(parent, start, goal);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
                parent[i] = node;  // 현재 노드를 부모로 설정
            }
        }
    }

    printf("목적지에 도달할 수 없습니다.\n");
}

int main() {
    int graph[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {1, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 1},
        {0, 0, 0, 1, 1, 1, 0}
    };

    int start = 0;  // 시작 노드
    int goal = 6;   // 목적지 노드
    
    printf("BFS를 이용한 최단 경로 탐색 결과:\n");
    bfs(graph, start, goal, 7);

    return 0;
}
