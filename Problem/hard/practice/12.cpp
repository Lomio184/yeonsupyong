#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> common) {    
    if ( (common[1] - common[0]) == (common[2] - common[1]) )
    {
        return common[common.size()-1] + (common[1] - common[0]);
    }

    if ( common[1] / common[0] && common[2] / common[1] )
    {
        return common[common.size()-1] * common[1] / common[0] ;
    }
}

int main()
{
    vector<int> ranges = {2, 4, 8} ;

    cout << solution( ranges ) << endl ;;
    return 0;
}