#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
const ll INF = 1e16;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (ll i = (l); i < (r); i++)
#define reper(i, l, r) for (ll i = (r)-1; i >= (l); i--)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}
//--------------------------------------------------------------------------------//

int main() {
    init();
    ll N;
    cin>>N;
    string s1, s2;
    cin >> s1 >> s2;

    ll ans = (s1[0] == s2[0] ? 3 : 2);
    s1 = "#" + s1, s2 = "." + s2;
    vl stat(N + 1);
    stat[0] = 1;
    repe(i,1,N+1){
        if (s1[i] == s1[i - 1]){
            stat[i] = 1;
            continue;
        }

        if(s1[i]==s2[i]){
            if(stat[i-1]==0){
                ans *= 2;
                ans %= MOD;
            }
        }else{
            if(stat[i-1]==0)
                ans *= 2;
            else
                ans *= 3;
            ans %= MOD;
        }
    }

    cout << ans << endl;
}