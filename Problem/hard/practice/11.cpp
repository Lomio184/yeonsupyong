#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

bool compare( string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strNum ;

    for ( int idx = 0 ; idx < numbers.size() ; ++idx )
    {
        strNum.push_back(to_string(numbers[idx]));
    }

    sort( strNum.begin(), strNum.end(), compare );

    if ( strNum[0] == "0" )
    {
        return "0";
    }
    
    for ( string nums : strNum )
    {
        answer += nums ;
    }

    return answer;
}

int main()
{
    vector<int> numbers = {6, 10, 2};

    cout << solution( numbers ) << endl;
    return 0;
}