#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define P pair<ll,ll>

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    ll ans = 1;
    ll cnt = 0; // 現在おいてある石の数
    rep(i,N){
        int x;
        cin >> x;
        if(x < cnt*2 + 1){
            ans *= (cnt+1);
            ans %= mod;
            continue;
        }
        cnt++;
    }
    while(cnt > 0){
        ans *= cnt;
        ans %= mod;
        cnt--;
    }
    cout << ans << endl;
}