#include <bits/stdc++.h>
using namespace std;
#define dbg(x) #x "=" << x << " "
#define fore(i,a,b) for(int i=a,gon=b;i<gon;++i)
#define pb push_back
#define F first
#define S second
typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 50;
ll dp[N][N][2505];
int v[N];
int n, a;

ll f(int i, int k, int sum) {
    if (i == n) return k ? sum == a*k : 0;
    ll &r = dp[i][k][sum];
    if (r != -1) return r;
    r = f(i+1, k, sum) + f(i+1, k+1, sum+v[i]);
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
    cin >> n >> a;
    fore(i,0,n) cin >> v[i];
    memset(dp, -1, sizeof(dp));
    cout << f(0, 0, 0) << endl;
}
