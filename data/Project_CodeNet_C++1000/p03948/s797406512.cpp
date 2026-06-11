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

int inf = 4e18, mod = 1e9+7;

int32_t main()
{
    ios_base::sync_with_stdio(false); cout << fixed <<setprecision(0);
    int n,t; cin >> n >> t;
    vi arr(n), maxi(n,-inf);
    for(int i=0;i<n;i++) cin >> arr[i];
    int sup = -inf, sum = 0;
    for(int i = n-2;i>=0;--i) maxi[i] = max(maxi[i+1], arr[i+1]), sup=max(sup, maxi[i] - arr[i]);
    for(int i=0;i<n;i++) sum += (maxi[i] - arr[i]) == sup;
    cout << sum << endl;
    return 0;
}
