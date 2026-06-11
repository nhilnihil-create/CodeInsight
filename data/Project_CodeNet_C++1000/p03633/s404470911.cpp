#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define bp  __builtin_popcount
#define pb push_back
#define sz(s) (int)(s.size())
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
const int maxn=1e5+5;
const  double EPS = 1e-9;
const int mod = 1e9+7;
/*
ll GCD(ll a,ll b){return (a)?GCD(b%a,a):b;}
ll LCM(ll a, ll b){return a*b/GCD(a,b);}
ll fastpow(ll b, ll p)
{if(!p)return 1;ll ret = fastpow(b, p >> 1);ret *= ret;if(p&1)ret*= b;return ret;}
*/
int dx[] = { -1,-1,-1,0,+1,+1,+1,0 };   // directional array
int dy[] = { -1,0,+1,+1,+1,0,-1,-1 };

ll GCD(ll a,ll b)
{
    return b?GCD(b,a%b):a;
}
ll LCM(ll a, ll b)
{
   return a/GCD(a,b)*b;
}

int main()
{
    ios::sync_with_stdio(0);
    int n,i;
    ll ans,arr[101];
    while(~scanf("%d",&n))
    {
        ans=1LL;
        for(i=0; i<n; i++)
            scanf("%lld",&arr[i]);
        for(i=0; i<n; i++)
            ans=LCM(ans,arr[i]);
        printf("%lld\n",ans);
    }
}
