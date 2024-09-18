#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> lines) {
    vector<int> line_map(201, 0); 

    for (const auto& line : lines) {
        int start = line[0] + 100; 
        int end = line[1] + 100;   

        for (int i = start; i < end; ++i) {
            line_map[i]++; 
        }
    }

    int answer = 0;

    for (int i = 0; i < 201; ++i) {
        if (line_map[i] > 1) {
            answer++;
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> lines = {{0, 1}, {2, 5}, {3, 9}};

    cout << solution( lines ) << endl ;
    return 0;
}