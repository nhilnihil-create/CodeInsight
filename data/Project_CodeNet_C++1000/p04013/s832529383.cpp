#include <bits/stdc++.h>
using namespace std;
 
typedef long long           ll;
typedef vector<int>         vi;
typedef vector<ll>          vll;

#define ff                  first
#define sf                  scanf
#define pf                  printf
#define ss                  second
#define ppb                 pop_back
#define pb                  push_back
#define MP                  make_pair
#define MAXN                10000
#define MOD                 100000007
#define inf                 0x3f3f3f3f
#define PI                  (2.0*acos(0.0))
#define INF                 0x3f3f3f3f3f3f3f3f
#define rev(v)              reverse(all(v))
#define all(v)              v.begin(), v.end()
#define __lcm(x, y)         (x * y) / __gcd(x, y)
#define FOR(i, x, y)        for(int i = x; i < y; i++)
#define RFOR(i, x, y)       for(int i = x; i >= y; i--)
#define MEM(arr, val)       memset(arr, val, sizeof(arr));
#define unq(v)              (v).resize(unique(all(v)) - v.begin())
#define READ()              freopen("input.txt", "r", stdin)
#define WRITE()             freopen("output.txt", "w", stdout)
#define si(n)               scanf("%d", &n)
#define sl(n)               scanf("%lld", &n)
#define sii(a, b)           scanf("%d %d", &a, &b)
#define sll(a, b)           scanf("%lld %lld", &a, &b)
#define siii(a, b, c)       scanf("%d %d %d", &a, &b, &c)
#define slll(a, b, c)       scanf("%lld %lld %lld", &a, &b, &c)
#define siiii(a, b, c, d)   scanf("%d %d %d %d", &a, &b, &c, &d)
#define sllll(a, b, c, d)   scanf("%lld %lld %lld %lld", &a, &b, &c, &d)
#define vout(v)             for(int i = 0; i < v.size(); i++) {cout << v[i]; if(i < v.size() - 1) cout << ' '; else cout << endl;}

vll v(100);
ll n, a, tot, res = 0;
ll dp[99][99][3000];

ll call(ll pos, ll cnt, ll sum){
    if(pos == n){
        if((double)sum / cnt == a) return 1;
        return 0;
    }
    if(dp[pos][cnt][sum] != -1) return dp[pos][cnt][sum];
    
    ll val1 = 0, val2 = 0;
    val1 = call(pos + 1, cnt + 1, sum + v[pos]);
    val2 = call(pos + 1, cnt, sum);
    return dp[pos][cnt][sum] = val1 + val2;
}

int main(){
    #ifndef ONLINE_JUDGE
        double start = clock(); READ(); WRITE();
    #endif
        cin >> n >> a;
        v.resize(n);

        FOR(i, 0, n) cin >> v[i];
        MEM(dp, -1);
        cout << call(0, 0, 0) << endl;


    return 0;
}