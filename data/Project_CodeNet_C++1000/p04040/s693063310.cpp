#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int         int64_t
#define ii          pair<int,int>
#define dd          pair<double,double>
#define vi          vector<int>
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define checkBit(v, p)      (v&(1LL << p))
#define loop(i,a,b) for(int i = a;i < int(b);i++)
#define x           first
#define y           second
using namespace std;

int inf = 2e9, mod = 1e9+7;

int inv(int b, int e = mod - 2){
    if(e == 0) return 1;
    if(e == 1) return b;
    int cur = inv(b,e/2);
    return cur * cur % mod * (e%2?b:1) % mod;
}
vi fact(2e5 + 1), ifact(2e5 + 1);
int choose(int n, int k){
    return fact[n] * ifact[k] % mod * ifact[n-k] % mod;
}
int32_t main()
{
    ios_base::sync_with_stdio(false); cout << fixed <<setprecision(0);
    int n,m,a,b,sum = 0; cin >> n >> m >> a >> b;
    fact[0] = ifact[0] = 1;
    for(int i = 1; i <= 2e5;i++) fact[i] = fact[i-1] * i % mod, ifact[i] = ifact[i-1] * inv(i) % mod;
    for(int i = 0;i<n-a;i++){
        sum = (sum + choose(i + b - 1,i) * choose(n-i-1 + m-b-1,m-b-1) % mod) % mod;
    }
    cout << sum << endl;
    return 0;
}
