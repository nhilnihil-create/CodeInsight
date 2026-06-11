#include <bits/stdc++.h>
using namespace std;


void solve(){
    string s; cin >> s;
    for(int i = 0; i < s.size()-2; i++){
        if(s[i] == s[i+1] || s[i] == s[i+1] || s[i] == s[i+2] || s[i+1] == s[i+2]){
            cout << i+1 << " " << i+3 << "\n";
            return;
        }
    }
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] == s[i+1]){
            cout << i+1 << " " << i+2 << "\n";
            return;
        }
    }
    cout << "-1 -1\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    bool multitest = false;
//    multitest = true;
    if(multitest){
        int t; cin >> t;
        while(t--)
            solve();
    }
    else
        solve();
}




