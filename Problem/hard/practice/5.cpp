// LV.2  숫자 변환하기
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int x, int y, int n) {
    if (x == y) return 0; 

    queue<pair<int, int>> q; 
    unordered_set<int> visited; 

    q.push({x, 0});  
    visited.insert(x);

    while (!q.empty()) {
        int current = q.front().first;
        int count = q.front().second;
        q.pop();


        vector<int> next_states = {current + n, current * 2, current * 3};

        for (int next : next_states) {
            if (next == y) {
                return count + 1; 
            }
            if (next < y && visited.find(next) == visited.end()) {
                q.push({next, count + 1});
                visited.insert(next);
            }
        }
    }

    return -1;
}

int main()
{
    int x = 10 ;
    int y = 40 ;
    int n = 5  ;

    cout << solution( x,y,n ) << endl;

    return 0;
}