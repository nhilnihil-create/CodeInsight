#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, a[300010];
ll L[300010], R[300010];

signed main(){
    cin >> N;
    REP(i, 3 * N) cin >> a[i];
    L[0] = a[0];
    FOR(i, 1, N) L[i] = L[i - 1] + a[i];
    priority_queue<ll, vector<ll>, greater<ll>> que(a, a + N);
    FOR(i, N, 2 * N){
        if(a[i] < que.top()){
            L[i] = L[i - 1];
        }else{
            L[i] = L[i - 1] + a[i] - que.top();
            que.pop();
            que.push(a[i]);
        }
    }
    R[3 * N - 1] = a[3 * N - 1];
    for(ll i = 3 * N - 2; i >= 2 * N; i--) R[i] = R[i + 1] + a[i];
    priority_queue<ll, vector<ll>, less<ll>> que2(a + 2 * N, a + 3 * N);
    for(ll i = 2 * N - 1; i >= N; i--){
        if(que2.top() < a[i]){
            R[i] = R[i + 1];
        }else{
            R[i] = R[i + 1] + a[i] - que2.top();
            que2.pop();
            que2.push(a[i]);
        }
    }
    ll ans = LONG_LONG_MIN;
    FOR(i, N - 1, 2 * N){
        ans = max(ans, L[i] - R[i + 1]);
    }
    PRINT(ans);
    return 0;
}