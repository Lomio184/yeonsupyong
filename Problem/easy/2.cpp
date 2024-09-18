#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

bool is_parallel(vector<int>& dot1, vector<int>& dot2, vector<int>& dot3, vector<int>& dot4) {
    return (dot2[1] - dot1[1]) * (dot4[0] - dot3[0]) == (dot4[1] - dot3[1]) * (dot2[0] - dot1[0]);
}

int solution(vector<vector<int>> dots) {
    if (is_parallel(dots[0], dots[1], dots[2], dots[3])) return 1;
    if (is_parallel(dots[0], dots[2], dots[1], dots[3])) return 1;
    if (is_parallel(dots[0], dots[3], dots[1], dots[2])) return 1;
    
    return 0;  
}

int main()
{
    vector<vector<int>> dots = {{1, 4}, {9, 2}, {3, 8}, {11, 6}};

    cout << solution( dots ) << endl;
    return 0;
}