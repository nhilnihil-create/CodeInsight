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
using namespace __gnu_pbds;
int inf = 2e9, mod = 1e9 + 7;

typedef tree<
ii,
null_type,
less<ii>,
rb_tree_tag,
tree_order_statistics_node_update> ST;

int32_t main()
{
    ios_base::sync_with_stdio(false); cout << fixed <<setprecision(0);
    int n, k; cin >> n >> k;
    ST st;
    int sum = 0, res = 0;
    for(int i=0,a;i<=n;i++){
        if(i != 0) cin >> a;
        else a = 0;
        sum+=a;
        a = sum - (i) * k;
        res += st.order_of_key(ii(a,i));
        st.insert({a, i});
    }
    cout << res<<endl;
    return 0;
}
