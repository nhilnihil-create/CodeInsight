#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define ALL(a) a.begin(), a.end()
#define REP(i,a) for(ll i(0), _##i(a); i < _##i; ++i)
#define FOR(i,a,b) for(ll i(a), _##i(b); i <= _##i; ++i)
using namespace std;
using ll = long long;

void solve(){
    string s;
    cin >> s;

    int n = s.size();
    REP(i, n){
        if (i + 1 < n && s[i] == s[i + 1]){
            cout << i + 1 << " " << i + 2 << "\n";
            return;
        }
        if (i + 2 < n && s[i] == s[i + 2]){
            cout << i + 1 << " " << i + 3 << "\n";
            return;
        }
    }
    cout << "-1 -1\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    //cin >> T;
    FOR(i,1,T){
        solve();
    }
}
