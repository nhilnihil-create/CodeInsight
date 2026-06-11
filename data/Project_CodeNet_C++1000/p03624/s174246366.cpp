
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    string s; cin >> s;
    bool app[26];
    rep(i,26){
        app[i] = false;
    }
    for(int i = 0; s[i] != '\0'; i++){
        app[s[i] - 'a'] = true;
    }
    rep(i,26){
        if(!app[i]){
            cout << (char)(i+'a');
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}