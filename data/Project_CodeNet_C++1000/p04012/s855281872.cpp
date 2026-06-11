#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    for(int i = 0; i < 26; i++){
        char ch = 'a' + i;
        int cnt = 0;
        for(int j = 0; j < s.size(); ++j){
            if(s[j] == ch) cnt++;
        }
        cnt %=2;
        if(cnt!=0){
            cout << "No" <<endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main(){
    solve();
    return 0;
}