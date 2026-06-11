#include <bits/stdc++.h>
using namespace std;


void solve(){
    string s, ans;
    cin >> s;
    for(char c : s){
        if(c == '0')
            ans += "0";
        else if(c == '1')
            ans += "1";
        else if(!ans.empty()) ans.pop_back();
    }
    cout << ans << "\n";
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




