#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

vector<vector<int>> createGraph(int n, const vector<vector<int>>& wires) {
    vector<vector<int>> graph(n + 1);  
    for (const auto& wire : wires) {
        int u = wire[0];
        int v = wire[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return graph;
}

int bfs(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    int count = 0;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int minDiff = n;  

    for (int i = 0; i < wires.size(); ++i) {

        vector<vector<int>> tempWires = wires;
        tempWires.erase(tempWires.begin() + i);

        vector<vector<int>> graph = createGraph(n, tempWires);
        vector<bool> visited(n + 1, false);  

        int towerCount = bfs(1, graph, visited);

        int diff = abs(towerCount - (n - towerCount));

        minDiff = min(minDiff, diff);
    }

    return minDiff;
}

int main()
{
    int n = 9 ;

    vector<vector<int>> wires = {{1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9}};

    cout << solution( n, wires ) << endl;

    return 0;
}