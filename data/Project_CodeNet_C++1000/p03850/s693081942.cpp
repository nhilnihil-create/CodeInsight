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
int inf = 4e18;
int32_t main()
{
    ios_base::sync_with_stdio(false); cout << fixed <<setprecision(0);
    int n; cin >> n;
    int res = 0;
    vi arr(n), arr2, ps(n), ps2;
    arr2.pb(0);
    vector<char> si(n);
    si[0] = '+';
    for(int i=0;i<n;i++){
        if(i) cin >> si[i];
        cin >> arr[i];
        if(i) ps[i] = ps[i-1] + arr[i] * (si[i] == '+' ? 1 : -1);
        else ps[0] = arr[0];
        if(si[i] == '+') arr2.back() += arr[i];
        else arr2.pb(arr[i]);
    }
    ps2.pb(arr2[0]);
    for(int i=1;i<arr2.size();i++) ps2.pb(ps2.back() + arr2[i]);
    res = ps.back();
    for(int i=1, ind = 0;i<n;i++){
        if(si[i] == '-'){
            ++ind;
            res = max(res, ps[i-1] - arr2[ind] + ps2.back() - ps2[ind]);
        }
    }
    cout << res<<endl;
    return 0;
}
