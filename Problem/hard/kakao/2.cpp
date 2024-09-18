#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    map<string, set<string>> report_map;  // 신고자 -> 신고된 유저 집합
    map<string, int> report_count;        // 신고된 유저 -> 신고 횟수

    // 1. 신고 정보를 처리하며 중복 신고를 제거
    for (const string& rep : report) {
        int space_pos = rep.find(' ');
        string from_user = rep.substr(0, space_pos);       // 신고자
        string to_user = rep.substr(space_pos + 1);        // 신고된 유저

        // 신고자가 같은 유저를 중복 신고하지 않도록 set을 사용
        report_map[from_user].insert(to_user);
    }

    // 2. 신고 횟수를 계산
    for (const auto& entry : report_map) {
        for (const string& user : entry.second) {
            report_count[user]++;
        }
    }

    // 3. 정지된 유저를 확인하고, 신고한 유저에게 메일을 보낼 횟수를 계산
    for (const auto& entry : report_map) {
        const string& from_user = entry.first;
        for (const string& to_user : entry.second) {
            // 정지된 유저는 k번 이상 신고된 유저
            if (report_count[to_user] >= k) {
                // 신고한 유저에게 메일을 보내야 하므로 카운트 증가
                int idx = find(id_list.begin(), id_list.end(), from_user) - id_list.begin();
                answer[idx]++;
            }
        }
    }

    return answer;
}

int main()
{
    vector<string> id_list = {"muzi", "frodo", "apeach", "neo"};
    vector<string> report = {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
    int k = 2 ;

    vector<int> ans = solution( id_list, report, k ) ;

    vector<int>::const_iterator iter ;

    for ( iter = ans.begin() ; iter != ans.end() ; ++iter )
    {
        cout << *iter << "\t" ;
    }
    cout << endl ;
    
    return 0;
}