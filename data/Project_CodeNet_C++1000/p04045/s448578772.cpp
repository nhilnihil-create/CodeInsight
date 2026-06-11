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
#define Unique(n)        (n).erase(unique(s(n)), (n).end())
#define NumofDigits(n)   ((long long)log10(n)+1)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
const int maxn=1e5+5;
const  double EPS = 1e-9;
const int MOD = 1e9+7;
/*
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll fastpow(ll b, ll p)
{if(!p)return 1;ll ret = fastpow(b, p >> 1);ret *= ret;if(p&1)ret*= b;return ret;}
int dx[] = {- 1, 0, 0, 1, 0 };
int dy[] = { 0,- 1, 1, 0, 0 };*/
map<int,bool>mp;
int main()
{
    ios_base::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    for(int i=0; i<k; i++)
    {
        int d;
        cin>>d;
        mp[d]=true;
    }
    int ans=0;
    for(int i=n; ;i++)
    {
        bool ok=true;
        int j=i;
        while(j)
        {
            int tmp=j%10;
            if(mp[tmp])
            {
                ok=false;
                break;
            }
            j/=10;
        }
        if(ok)
          return cout<<i,0;
    }
}
