#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

int main(){
    int N, L, Q;
    cin >> N;
    int x[N];
    rep(i, N) cin >> x[i];
    cin >> L >> Q;
    //next[i][j]:=jから2^i日かけて到達できる最も座標の大きい点
    int next[30][N], now = 0;
    rep(i, N){
        while(now < N-1 && x[now+1] <= x[i]+L) now++;
        next[0][i] = now;
    }
    rep2(i, 1, 29){
        rep(j, N){
            next[i][j] = next[i-1][next[i-1][j]];
        }
    }
    rep(i, Q){
        int A, B;
        cin >> A >> B;
        A--, B--;
        if(A > B) swap(A, B);
        int ans = 0;
        now = A;
        rep3(j, 29, 0){
            if(next[j][now] < B){
                now = next[j][now];
                ans |= (1<<j);
            }
        }
        cout << ans+1 << endl;
    }
}