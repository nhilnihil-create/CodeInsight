#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    string ans = "";
    rep(i,s.size()) {
        if(s[i]=='0') ans.push_back('0');
        else if(s[i]=='1') ans.push_back('1');
        else {
            if(ans=="") continue;
            ans.pop_back();
        }
    }
    cout << ans << endl;
    return 0;
}