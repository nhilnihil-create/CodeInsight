#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
const int MOD = 1000000007;

int N, M;
int fact[100100];
 
signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> M;
    fact[0] = 1;
    for (int i=1; i<100100; i++) fact[i] = fact[i-1]*i%MOD;
    if (N==M) cout << 2*(fact[N]*fact[M]%MOD)%MOD << endl;
    else if (abs(N-M)==1) cout << fact[N]*fact[M]%MOD << endl;
    else cout << 0 << endl;
}