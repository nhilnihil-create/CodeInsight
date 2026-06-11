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
int inf = 2e9, mod = 1e9 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false); cout << fixed <<setprecision(0);
    int n, m; cin >> n >> m;
    int val = 0;
    for(int i=0, cur, last;i<n;i++){
        cin >> cur;
        if(i) val = (val + i * (n - i) % mod * (cur - last) % mod ) % mod;
        last = cur;
    }
    int res = 0;
    for(int i=0, cur, last;i<m;i++){
        cin >> cur;
        if(i) res = (res + i * (m-i) % mod * (cur - last) % mod * val % mod) % mod;
        last = cur;
    }
    cout << res << endl;
    return 0;
}
