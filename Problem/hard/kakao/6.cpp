// 거리두기 확인하기 2021 kakao
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dx[] = {-1, 1, 0, 0}; 
int dy[] = {0, 0, -1, 1};

// 거리두기 규칙을 준수하는지 확인하는 함수
bool isSafe(vector<string>& place, int x, int y) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(5, vector<bool>(5, false));
    
    q.push({x, y});
    visited[x][y] = true;
    
    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            int dist = abs(nx - x) + abs(ny - y);
            
            // 좌표가 범위를 벗어나지 않고 방문하지 않은 경우
            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && !visited[nx][ny]) 
            {
                visited[nx][ny] = true;
                
                if (place[nx][ny] == 'P' && dist <= 2) 
                {
                    // 응시자가 거리두기 규칙을 위반
                    return false;
                } else if (place[nx][ny] == 'O' && dist < 2) 
                {
                    // 빈 테이블이 있는 경우 계속 탐색
                    q.push({nx, ny});
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (int i = 0; i < 5; ++i) {
        bool isValid = true;
        
        for (int x = 0; x < 5 && isValid == true ; ++x) 
        {
            for (int y = 0; y < 5 && isValid == true ; ++y) 
            {
                if (places[i][x][y] == 'P') 
                {
                    // 응시자가 앉아 있는 위치에서 거리두기 확인
                    if (false == isSafe(places[i], x, y)) 
                    {
                        isValid = false;
                    }
                }
            }
        }
        answer.push_back(isValid ? 1 : 0);
    }
    
    return answer;
}

int main()
{
    vector<vector<string>> places = {{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};

    vector<int> result = solution( places ) ;

    for ( int idx = 0 ; idx < result.size() ; ++idx )
    {
        cout << result[idx] << endl;
    }

    return 0;
}