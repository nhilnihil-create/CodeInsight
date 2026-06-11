#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976

int main()
{
    string s; cin >> s;
    ll n = s.size();
    ll cnt[26];
    rep(i,26) cnt[i] = 0;
    rep(i,n) cnt[s[i]-'a']++;
    ll ans = 1 + (n * (n-1)) / 2;
    rep(i,26){
        ll m = cnt[i];
        ans -= (m * (m-1))/2;
    }
    cout << ans << endl;
}