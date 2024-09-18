#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    for ( int idx = 0 ; idx < db.size() ; ++idx )
    {
        if ( db[idx][0] == id_pw[0] )
        {
            if ( db[idx][1] == id_pw[1] )
            {
                return "login" ;
            }
            else
            {
                return "wrong pw";
            }
        }
    }

    return "fail";
}

int main()
{
    vector<string> id_pw = {"meosseugi", "1234"};
    vector<vector<string>> db = {{"rardss", "123"}, {"yyoom", "1234"}, {"meosseugi", "1234"}} ;

    cout << solution( id_pw, db ) << endl;
    return 0;
}