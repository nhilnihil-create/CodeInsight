#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    for(int i = 0; i < s.size()-1; ++i){
        if(s[i] == s[i+1]) {
            cout << i+1 << " " << i + 2 << endl;
            return;
        }
        if(s[i] == s[i + 2]) {
            cout << i+1 << " " << i + 3 << endl;
            return;
        }
    }
    cout << -1 << " " << -1 << endl;
}

int main(){
    solve();
    return 0;
}