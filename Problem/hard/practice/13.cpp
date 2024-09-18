#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> array) {
    map<int, int> maps; 

    for (int num : array) {
        maps[num]++;
    }

    // 최빈값 찾기
    int max_count = 0;  
    int mode_value = -1; 
    bool multiple = false; 

    for (const auto& entry : maps) {
        if (entry.second > max_count) {
            max_count = entry.second;
            mode_value = entry.first;
            multiple = false;  
        } else if (entry.second == max_count) {
            multiple = true;  
        }
    }

    if (multiple) {
        return -1;
    }
    return mode_value;
}

int main()
{
    vector<int> array = {1, 2, 3, 3, 3, 4};

    cout << solution(array) << endl;

    return 0;
}