/** "Ever tried.
         Ever failed.
               No matter.
                   Try Again.
                        Fail again.
                             Fail better.**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define bp  __builtin_popcount
#define pb push_back
#define loop(i,n) for(int i = 0;i < int(n);i++)
#define sz(s) (int)(s.size())
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define setdp memset(dp,-1,sizeof(dp))
#define fr first
#define sc second
#define NumofDigits(n)   ((long long)log10(n)+1)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
const int maxn=2e6+5;
const  double EPS = 1e-9;
const int MOD = 1e9+7;
/*
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll fastpow(ll b, ll p)
{if(!p)return 1;ll ret = fastpow(b, p >> 1);ret *= ret;if(p&1)ret*= b;return ret;}
int dx[] = {- 1, 0, 0, 1, 0 };
int dy[] = { 0,- 1, 1, 0, 0 };*/
inline void File()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,sum=0;
    cin>>n;
    vector<int>v;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        if(x%10!=0)
            v.pb(x);
        sum+=x;
    }
    if(sz(v)==0&&sum%10==0)
        return  cout<<0<<endl,0;
    if(sum%10==0)
        sum-=*min_element(all(v));

    cout<<sum<<endl;
}
