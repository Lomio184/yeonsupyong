// LV.2 귤 고르기
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    unordered_map<int,int> countMap ;

    for ( int size : tangerine )
    {
        countMap[size]++;
    }

    vector<int> counts;
    for (auto& pair : countMap) {
        counts.push_back(pair.second);
    }
    sort(counts.begin(), counts.end(), greater<int>()); 

    int total = 0;
    
    for (int count : counts) {
        total += count;  
        answer++;        
        if (total >= k)  
            break;
    }

    return answer;
}

int main()
{
    int k = 6; 
    vector<int> tan = {1, 3, 2, 5, 4, 5, 2, 3};

    solution( k, tan );
    return 0;
}