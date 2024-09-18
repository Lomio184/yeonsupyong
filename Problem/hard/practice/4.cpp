// LV.2 뒤에 있는 큰 수 찾기
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1); 
    stack<int> st; 

    for (int i = numbers.size() - 1; i >= 0; --i) {
        while (!st.empty() && st.top() <= numbers[i]) {
            st.pop();
        }
        
        if (!st.empty()) 
        {
            answer[i] = st.top();
        }
        
        st.push(numbers[i]);
    }

    return answer;
}

int main()
{
    vector<int> numbers = {9, 1, 5, 3, 6, 2};

    vector<int> ans = solution( numbers) ;

    for ( int i = 0 ; i < ans.size() ; ++i )
    {
        cout << ans[i] << " ";
    }

    cout << endl ;
    return 0;
}