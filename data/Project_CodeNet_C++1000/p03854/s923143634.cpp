#include<bits/stdc++.h>
using namespace std;

int main(void){
    string s;
    string words[4] = {"dream", "dreamer", "erase", "eraser"};
    cin >> s;
    reverse(s.begin(), s.end());
    for(int i = 0; i < 4; i++){
        reverse(words[i].begin(), words[i].end());
    }
    while(!s.empty()){
        bool hit = false;
        for(int i = 0; i < 4; i++){
            string sub = s.substr(0, words[i].size());
            if(sub == words[i]){
                s.erase(s.begin(), s.begin() + words[i].size());
                hit = true;
                break;
            }
        }
        if(!hit){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}