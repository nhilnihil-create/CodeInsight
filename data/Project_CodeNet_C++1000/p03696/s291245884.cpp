#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
// ())((
int main() {
    int n;
    string s;
    cin >> n >> s;
    int p = 0;
    int l = 0;
    rep(i,s.size()) {
        if(s[i]=='(') p++;
        else {
            if(!p) l++;
            else --p;
        }
    }
    int r = p;
    string ans = "";
    rep(i,l) ans+='(';
    ans+=s;
    rep(i,r) ans+=')';
    cout << ans << endl;
    return 0;
}