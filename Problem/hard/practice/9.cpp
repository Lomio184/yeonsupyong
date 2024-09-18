#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;


int solution(string word) 
{
    int answer = 0;
    
    vector<char> vowels = {'A', 'E', 'I', 'O', 'U'};
    vector<int> weights = {781, 156, 31, 6, 1 };

    for ( int idx = 0 ; idx < word.size() ; ++idx )
    {
        int pos = find(vowels.begin(), vowels.end(), word[idx]) - vowels.begin() ;
        answer += pos * weights[idx] ;
        answer++;
    }
    
    return answer;
}

int main()
{
    string txt = "AAAAE";

    cout << solution( txt ) << endl ;
    return 0;
}