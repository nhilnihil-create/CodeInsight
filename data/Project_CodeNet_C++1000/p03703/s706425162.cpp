#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;   
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()
#define sz(x) (ll)x.size() 

ll p[200005],a[200005];
map<ll,ll>M;
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,i,j,k,x,y,t,m;

    cin >> n >> k;
    for(i=1;i<=n;i++)
        cin >> a[i];

    for(i=1;i<=n;i++)
        p[i]=p[i-1]+a[i];

    ll ans=0;
    ordered_set os;
    for(i=1;i<=n;i++)
    {
        if(p[i]>=k*i)
            ans++;

        x=p[i]-k*i;
        ll c=0;
        if(M.find(x)!=M.end())
            c=M[x];

        ans+=(ll)os.order_of_key({x,-i})+c;
        M[x]++;
        os.insert({x,-i});
    }
    cout<<ans<<endl;
}