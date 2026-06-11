#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    string s;
    cin >> s;
    ll N = s.length();
    vector<ll> c(26, 0);
    for (int i = 0; i < N; i++) {
        c[s[i] - 'a']++;
    }

    ll ans = 1;
    ans += N*(N+1)/2;
    for (int i = 0; i < 26; i++) {
        ans -= c[i]*(c[i]+1)/2;
    }
    printf("%lld\n", ans);
}
