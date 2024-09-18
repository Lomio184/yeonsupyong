// LV.1 공원 산책 
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> simpleSplit( string txt )
{
    int space_pos = txt.find(' ') ;
    vector<string> dirCnt = { txt.substr( 0, space_pos ), txt.substr( space_pos+1 ) };

    return  dirCnt ;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer; // 움직일때마다 업데이트
    int maxWidth  = park[0].size() - 1 ;
    int maxHeight = park.size() - 1;

    // 1. 시작지점 탐색
    for ( int idx = 0 ; idx < park.size() ; ++idx )
    {
        int pos = park[idx].find('S');

        if ( pos != string::npos )
        {
            answer.push_back( idx ) ;
            answer.push_back( pos ) ;
            break ;
        }
    }
    cout << answer[0] << " " << answer[1] << endl ;

    for ( int idx = 0 ; idx < routes.size() ; ++idx )
    {
        vector<string> dirCnt = simpleSplit( routes[idx] ) ;
        int cnt = stoi(dirCnt[1]) ;
        bool cmd = true ;

        if ( "E" == dirCnt[0] ) 
        {
            if ( answer[1] + cnt > maxWidth )
            {
                continue ;
            }

            for ( int jdx = 0 ; jdx <= cnt ; ++jdx )
            {
                if ( 'X' == park[answer[0]][answer[1]+jdx] )
                {
                    cmd = false ;
                    break ;
                }
            }
            
            if ( cmd == true )
            {
                answer[1] += cnt ;
            }
        }
        else if ( "S" == dirCnt[0] )
        {
            if ( answer[0] + cnt > maxHeight )
            {
                continue ;
            }

            for ( int jdx = 0 ; jdx <= cnt ; ++jdx )
            {
                if ( 'X' == park[answer[0]+jdx][answer[1]] )
                {
                    cmd = false ;
                    break ;
                }
            }
            
            if ( cmd == true )
            {
                answer[0] += cnt ;
            }
        }
        else if ( "W" == dirCnt[0] ) 
        {
            if ( answer[1] - cnt < 0 )
            {
                continue ;
            }

            for ( int jdx = 0 ; jdx <= cnt ; ++jdx )
            {
                if ( 'X' == park[answer[0]][answer[1]-jdx] )
                {
                    cmd = false ;
                    break ;
                }
            }
            
            if ( cmd == true )
            {
                answer[1] -= cnt ;
            }
        }
        else if ( "N" == dirCnt[0] ) 
        {
            if ( answer[0] - cnt < 0 )
            {
                continue ;
            }

            for ( int jdx = 0 ; jdx <= cnt ; ++jdx )
            {
                if ( 'X' == park[answer[0]-jdx][answer[1]] )
                {
                    cmd = false ;
                    break ;
                }
            }
            
            if ( cmd == true )
            {
                answer[0] -= cnt ;
            }
        }
        cout << answer[0] << " " << answer[1] << endl ;
    }

    return answer;
}

int main( int argc, char **argv )
{
    vector<string> park = { "OXXO", "XSXO", "XXXX" } ;
    vector<string> routes = { "E 1", "S 1" } ;

    solution( park, routes ) ;
    return 0;
}