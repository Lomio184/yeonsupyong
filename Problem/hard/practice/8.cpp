#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> pq ;
    int total = n ;
    int rounds = 0 ;

    for ( int idx = 0 ; idx < enemy.size() ; ++idx )
    {
        total -= enemy[idx] ;
        pq.push( enemy[idx] ) ;
        rounds++;

        if  (total < 0 )
        {
            if ( k > 0 )
            {
                total += pq.top() ;
                pq.pop() ;
                k--;
            }
            else
            {
                rounds--;
                break;
            }
        }
    }

    return rounds;
}

int main()
{
    int n = 7 ;
    int k = 3  ;
    vector<int> enemy = {4, 2, 4, 5, 3, 3, 1};

    cout << solution( n, k, enemy ) << endl ;

    return 0;
}