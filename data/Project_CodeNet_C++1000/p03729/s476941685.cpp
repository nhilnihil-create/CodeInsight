#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;
int main(void) {
    string s[3];
    rep(i, 3) cin >> s[i];
    bool ok = false;
    if(s[0][s[0].size()-1] == s[1][0]&&s[1][s[1].size()-1]==s[2][0])
    ok = true;
    if(ok) cout << "YES";
    else cout << "NO";
}
