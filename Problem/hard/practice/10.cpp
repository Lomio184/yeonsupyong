#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;

    for (int x = 0; x <= d; x += k) 
    {
        int max_y = (int)sqrt((long long)d * d - (long long)x * x);
        
        answer += (max_y / k) + 1; 
    }

    return answer;
}

int main()
{
    int k = 1;
    int d = 5;

    cout<< solution( k,d) << endl;

    return 0;
}