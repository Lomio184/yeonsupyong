// LV.2 두 원 사이의 정수 쌍
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

    // 원의 방정식 활용 : x^2 + y^2 = r2^2
    for (int x = 1; x <= r2; ++x) 
    {
        // 역치 -> y = sqrt(r2^2-x^2) -> floor 로 정수형으로 내림
        long long max_y_r2 = (long long)floor(sqrt((long long)r2 * r2 - (long long)x * x));

        long long min_y_r1 = 0;
        if (x < r1) {
            min_y_r1 = (long long)ceil(sqrt((long long)r1 * r1 - (long long)x * x));
        }


        answer += (max_y_r2 - min_y_r1+ 1);
    }

    answer *= 4;

    return answer;
}

int main( int argc, char **argv )
{
    long long r1 = 2 ;
    long long r2 = 3 ;

    cout << solution( r1, r2 ) << endl;

    return 0;
} 