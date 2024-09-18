#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i <= right; ++i) {
        int row = i / n;  
        int col = i % n; 
        answer.push_back(max(row, col) + 1); 
    }
    return answer;
}
/*
1 2 3 4 
2 2 3 4
3 3 3 4
4 4 4 4
*/
int main()
{
    int n = 4 ;
    long long left = 2 ;
    long long right = 5 ;

    solution( n, left, right ) ;
    return 0;
}