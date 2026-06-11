#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, l;
    cin >> n >> l;
    string ans="";
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    sort(all(s));
    rep(i,n) ans+=s[i];
    cout << ans << endl;
    return 0;
}