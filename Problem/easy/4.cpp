#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int sum( vector<int>& answer )
{
    int result = 0 ;

    for ( int num : answer )
    {
        result += num ;
    }

    return result ;
}

vector<int> solution(int num, int total) {
    vector<int> answer;

    int start = (total / num) - (num - 1) / 2;

    cout << start << endl;

    for (int i = 0; i < num; ++i) {
        answer.push_back(start + i);
    }

    return answer;
}

int main()
{
    int num = 5 ;
    int total = 5 ;

    vector<int> result = solution( num, total ) ;

    for ( int idx = 0 ; idx < result.size() ; ++idx )
    {
        cout << result[idx] << " " ;
    }

    cout << endl ;
    return 0;
}