#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    string s;
    cin >> s;

    ll cnt[26] = {};
    rep(i, s.size())cnt[s[i]-'a']++;

    ll ans = s.size()*(s.size()-1)/2 + 1;
    rep(i, 26)ans -= cnt[i]*(cnt[i]-1)/2;

    cout << ans << endl;
}