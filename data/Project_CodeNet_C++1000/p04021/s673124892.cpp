#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define F first
#define S second
#define pi acos(-1)
using ll = long long;
using namespace std;
using namespace __gnu_pbds;
using vl = vector<ll>;
using pll =  pair<ll,ll>;
const ll mod = 1000000007;
const ll infi = 1000000000000000;
const ll md = 998244353;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;


ll power(ll x,ll y){
    ll res = 1;
    while(y){
        if(y&1)
            res = (res*x)%md;
        x = (x*x)%md;
        y = y/2;
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    vl a(n);
    ll ans=0;
    set<int> s;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i%2 == 0)
            s.insert(a[i]);
    }

    sort(a.begin(), a.end());

    for(int i=0;i<n;i++){
        if(i%2 == 0)
            s.erase(a[i]);
    }

    cout<<s.size();
}
 
int main()
{
    
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //int n; cin>>n; for (int i = 0; i < n; ++i)
    solve();
    return 0;
}
