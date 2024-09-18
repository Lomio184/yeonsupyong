#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

static int final_val = 0 ;

void recursive( unordered_map<string,int>& dict, string& tmp, string& msg, int& k )
{
    // 인덱스 초과하지 않게 방지
    if ( k >= msg.size() )
    {
        return ;
    }

    tmp += msg[k] ;

    // 사전 탐색 후 있으면 지속 탐색
    if ( dict.find( tmp ) != dict.end() )
    {
        recursive( dict, tmp, msg, ++k ) ;
    }
    else // 없으면 사전 등록 후 맨 마지막 요소 제거
    {
        final_val++ ;
        dict[tmp] = final_val ;
        tmp.pop_back();
    }

    return ;
}

vector<int> solution(string msg) {
    vector<int> answer;
    size_t msg_len = msg.size() ;
    unordered_map<string, int> dict ; 

    for (char c = 'A'; c <= 'Z'; c++) 
    {
        dict[string(1,c)] = c - 'A' + 1 ;

        if ( c == 'Z' )
        {
            final_val = c - 'A' + 1 ;
        }
    }

    int k = 0 ;

    for ( int idx = 0 ; idx < msg_len ; ++idx ) 
    {

        if ( k != 0 && k > idx )
        {
            continue;
        }

        string tmp = "";

        recursive( dict, tmp, msg, k );

        answer.push_back( dict[tmp] ) ;
    }
    return answer;
}

int main()
{
    string msg = "TOBEORNOTTOBEORTOBEORNOT";

    vector<int> ans  = solution( msg ) ;

    

    for ( int idx = 0 ; idx < ans.size() ; ++idx )
    {
        cout << ans[idx] << " " ;
    }
    cout << endl ;
    
    return 0;
}