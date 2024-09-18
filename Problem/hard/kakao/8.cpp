//LV.3 불량사용자
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <regex>

using namespace std;

int lcs( const string& str1, const string& str2 )
{
    int n = str1.length() ;
    int m = str2.length() ;

    if ( n != m )
    {
        return 0 ;
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for ( int i = 1; i <= n ; ++i )
    {
        for ( int j = 1; j <= m; ++j )
        {
            if ( str1[i-1] == str2[i-1] )
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m] ;
}


void dfs(int idx, vector<vector<string>>& candidates, set<set<string>>& result, set<string>& current) {
    if (idx == candidates.size()) {
        result.insert(current);  
        return;
    }

    for (const string& user : candidates[idx]) {
        if (current.find(user) == current.end()) {
            current.insert(user);
            dfs(idx + 1, candidates, result, current);
            current.erase(user);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<vector<string>> candidates; 


    for (const string& ban : banned_id) {
        string regex_pattern = "^" + regex_replace(ban, regex("\\*"), ".*") + "$"; 
        regex re(regex_pattern);
        vector<string> matching_users;

        for (const string& user : user_id) {
            if (regex_match(user, re)) { 
                matching_users.push_back(user);
            }
        }

        candidates.push_back(matching_users); 
    }

    set<set<string>> result; 
    set<string> current;  

    dfs(0, candidates, result, current);

    return result.size(); 
}

int main()
{
    vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id = {"*rodo", "*rodo", "******"};

    int ans = solution( user_id, banned_id ) ;

    cout << ans << endl ;

    return 0;
}