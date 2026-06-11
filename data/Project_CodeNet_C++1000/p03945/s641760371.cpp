#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string t = "";
    for(int i = 0; i < n-1; ++i) if(s[i]!=s[i+1]) t.push_back(s[i]); 
    ll ans = t.size();
    cout << ans << endl;
    return 0;
}