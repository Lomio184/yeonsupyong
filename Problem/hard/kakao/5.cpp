#include <string>
#include <vector>
#include <iostream>
#include <set>  
#include <algorithm>

using namespace std;

void dfs(int node, vector<vector<int>>& tree, vector<int>& info, int sheep, int wolf, vector<int>& nextNodes, int& maxSheep) {
    if (info[node] == 0) {
        sheep++;  
    } else {
        wolf++;  
    }

    if (wolf >= sheep) {
        return; // backtracking
    }

    maxSheep = max(maxSheep, sheep);

    // 다음에 갈 수 있는 노드 목록에서 현재 노드를 제외
    vector<int> newNextNodes = nextNodes;
    newNextNodes.erase(remove(newNextNodes.begin(), newNextNodes.end(), node), newNextNodes.end());

    for (int child : tree[node]) {
        newNextNodes.push_back(child);
    }


    for (int nextNode : newNextNodes) {
        dfs(nextNode, tree, info, sheep, wolf, newNextNodes, maxSheep);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int maxSheep = 0;
    int n = info.size();

    vector<vector<int>> tree(n);
    for (auto& edge : edges) {
        tree[edge[0]].push_back(edge[1]);
    }

    vector<int> nextNodes = {0};
    dfs(0, tree, info, 0, 0, nextNodes, maxSheep);

    return maxSheep;
}

int main() {
    vector<int> info = {0,0,1,1,1,0,1,0,1,0,1,1};
    vector<vector<int>> edges = {
        {0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9}
    };

    int result = solution(info, edges);
    cout << "Total number of sheep: " << result << endl;

    return 0;
}
