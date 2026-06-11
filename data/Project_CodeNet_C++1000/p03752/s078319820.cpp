#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, n) for(int i = 1; i <= n; i++)
template<class T> inline int chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline int chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1<<29;
const ll LINF = 1LL<<58;
const int mod = 1000000007;


int main(){
    int n, k;
    cin >> n >> k;
    ll ans = LINF;
    vector<ll> A(n + 1, 0);
    for (int i = 0; i < n; i++) cin >> A[i + 1];
    for (int bit = 0; bit < 1 << n; bit++) {
        ll money = 0;
        int cnt = 0;
        ll nax = 0;
        for (int i = 0; i < n; i++) {
            bool flag = (bit >> i & 1);
            if(flag){
                ll h = A[i + 1];
                chmax(h, nax + 1);
                chmax(nax, h);
                money += max(0LL, h - A[i + 1]);
                cnt++;
            } else {
                if(A[i + 1] > nax) cnt++;
                chmax(nax, A[i + 1]);
            }
        }
        if(cnt >= k) {
            chmin(ans, money);
        }
    }
    cout << ans << endl;
    return 0;
}