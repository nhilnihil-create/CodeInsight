#include <iostream>
#include <sstream>  // istringstream
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()
{   
    string s;
    cin >> s;
    // 端の文字と偶奇のみで求まる

    bool game_cont = true;    
    int turn = 1;
    while(game_cont){
        game_cont = false;
        for(int i=0; i<s.length()-2; ++i){
            // if(s.length() == 3){
            //     break;
            // }
            if(s[i] != s[i+2]){
                s.erase(i+1, 1);
                // cout << s << " " << turn << endl;
                game_cont = true;
                turn++;
                break; // forループを抜ける
            }
        }
        if(!game_cont){
            // cout << "set " << turn << endl;
        }
    }

    if(turn%2 == 0){
        cout << "First" << endl;        
    }
    else{
        cout << "Second" << endl;
    }
    return 0;
}