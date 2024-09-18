#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std ;

// 달리기 경주 Lv.1

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> rankMap ;

    for ( int idx = 0 ; idx < players.size() ; ++idx )
    {
        rankMap[players[idx]] = idx ;
    }

    for ( const string& calledPlayer : callings )
    {
        int currentRank = rankMap[calledPlayer];

        if ( currentRank> 0 )
        {
            string frontPlayer = players[currentRank-1];

            swap( players[currentRank], players[currentRank-1] ) ;

            rankMap[calledPlayer]--;
            rankMap[frontPlayer]++;
        }
    }

    vector<string> answer(players.size());
    copy( players.begin(), players.end(), answer.begin() ) ;

    return answer;
}

int main()
{
    std::vector<std::string> players = {
        "mumu", "soe", "poe", "kai", "mine"
    };
    std::vector<std::string> callings = {
        "kai", "kai", "mine", "mine"
    };

    vector<string> ans = solution( players, callings ) ;

    for ( int idx = 0 ; idx < ans.size() ; ++idx )
    {
        cout << ans[idx] << "\t" ;
    }
    cout << "\n" ;
}