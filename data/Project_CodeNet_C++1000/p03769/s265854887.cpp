//InTheNameOfGod
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define rep(i,j,k) for(int i=j;i<k;++i)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define pb push_back
#define lb(i) i&(-i);
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn =300;
ll n,cnt,w;
ll a[maxn];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    while((1LL<<cnt)-1<=n)
    {
        cnt++;
    }
    cnt--;
    n-=(1LL<<cnt)-1;
    rep(i,1,cnt+1)
    {
        a[w++]=2*i;
    }
    rrep(i,cnt-1,0)
    {
        if((1LL<<i)&n)
        {
            a[w++]=2*i+1;
        }
    }
    cout<<w+100<<endl;
    rep(i,0,w)
    {
        cout<<a[i]<<' ';
    }
    rep(i,1,101)
    {
        cout<<i<<' ';
    }
    return 0;
}
