#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i < (n+1); ++i)
using namespace std;
using ll = long long;
const ll INF = +10010010000;

typedef pair<ll,ll> P;
const ll MO = 1000000007;

int main(){
    string s;
    cin >> s;
    char pre = s[0];
    ll ans = 0;
    rrep(i,s.size()-1){
        if(pre!=s[i])ans++;
        pre = s[i];
    }
    cout <<ans << endl;
    return 0;
}