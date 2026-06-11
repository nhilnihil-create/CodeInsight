#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e18;

int main(){
    ll N;
    cin >> N;
    ll p[N+1], q[N+1], a[N+1], b[N+1];
    rep2(i, 1, N+1){
        cin >> p[i];
        q[p[i]] = i;
        a[i] = i;
        b[i] = N+1-i;
    }
    ll suml[N+1], sumr[N+1];
    suml[1] = 0;
    rep2(i, 1, N){
        suml[i+1] = suml[i] + N-q[i];
    }
    sumr[N] = 0;
    for(int i = N; i > 1; i--){
        sumr[i-1] = sumr[i] + N-q[i];
    }
    rep2(i, 1, N+1){
        a[i] += suml[i];
        b[i] += sumr[i];
    }
    rep2(i, 1, N) cout << a[i] << ' ';
    cout << a[N] << endl;
    rep2(i, 1, N) cout << b[i] << ' ';
    cout << b[N] << endl;
}