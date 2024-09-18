#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

#define MAX_MINUTE 1439  

string hhmmToMinute( string hhmm )
{
    int space_del = hhmm.find(":") ;
    string hh = hhmm.substr( 0, space_del );
    string mm = hhmm.substr( space_del + 1 ) ;

    return to_string((stoi(hh)*60) + stoi(mm));
}

vector<string> split( string txt )
{
    std::istringstream iss( txt ) ;
    vector<string> result ;
    string word ;

    while ( iss >> word )
    {
        result.push_back( word );
    }

    result[0] = hhmmToMinute( result[0] ) ;

    return result; 
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> result;  
    map<string, int> in_time; 
    vector<vector<string>> tmp;

    int basic_time = fees[0];
    int basic_fee = fees[1];
    int each_time = fees[2];
    int each_fee = fees[3];

    for (int idx = 0; idx < records.size(); ++idx) {
        vector<string> txtSplit = split(records[idx]);

        if (txtSplit[2] == "IN") {
            in_time[txtSplit[1]] = stoi(txtSplit[0]);
        } 
        else if (txtSplit[2] == "OUT") {
            result[txtSplit[1]] += (stoi(txtSplit[0]) - in_time[txtSplit[1]]);
            in_time.erase(txtSplit[1]); 
        }
    }

    for (const auto& entry : in_time) {
        result[entry.first] += (MAX_MINUTE - entry.second);
    }

    for (const auto& entry : result) {
        int total_time = entry.second;

        if (total_time <= basic_time) {
            answer.push_back(basic_fee);
        } else {
            answer.push_back(basic_fee + ceil((double)(total_time - basic_time) / each_time) * each_fee);
        }
    }

    return answer;
}

int main()
{
    vector<int> fees = { 1, 461, 1, 10 } ;
    vector<string> records = {
        "00:00 1234 IN"
    };

    solution( fees, records ) ;
}