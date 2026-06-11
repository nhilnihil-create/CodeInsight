//Be Name Khoda
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma optimize O3
using namespace __gnu_pbds;
using namespace std;
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset =  tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long int LL;
typedef LL ll;
typedef long double ld;
typedef string str;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef stringstream strs;
 
#define X first
#define Y second
#define PB push_back
#define For(i,a,b) for (int i=a;i<b;i++)
#define Ford(i,a,b) for (int i=a;i>=b;i--)
#define smax(a,b) a=max(a,b)
#define smin(a,b) a=min(a,b)
#define SZ(a) ((ll)a.size())
#define ER(a) cout << #a << ' ' << a << endl
#define LB(a,n,x) (lower_bound(a,(a)+(n),x)-(a))
#define RET(x) { cout << x; exit(0); } 
const ll M=1e5+5,LG=32,SM=600+5,inf=1e18+5;
ll mod=1e9+7;


ll n,m,k;
ll rfog[M];
 
void fog(const ll f[M],const ll g[M])
{
    For(i,0,n)
        rfog[i]=f[g[i]];
}

void fil(ll a[M],const ll b[M])
{
    For(i,0,n)
        a[i]=b[i];       
}

ll jay[M];
ll x[M];
ll res[M];
ll z[M];
ll z2[M];

int main()
{
    cin >> n;
    For(i,0,n)
        cin >> x[i];
    cin >> m >> k;
    iota(jay,jay+n-1,0);
    For(i,0,m)
    {
        ll x;
        cin >> x;
        swap(jay[x-2],jay[x-1]);
    }
    n--;
    //For(i,0,n) { ER(i); ER(jay[i]); }
    iota(res,res+n,0);
    /*For(i,0,k)
    {
        fog(res,jay);
        fil(res,rfog);
        For(i,0,n) { cout << res[i] << ' '; }
        cout << '\n';
    }*/
    // power jaygasht
    {
        iota(res,res+n,0);
        fil(z,jay);
        For(i,0,64)
        {
            if ((k>>i)&1)
            {
                fog(res,z);
                fil(res,rfog);
            }
            fog(z,z);
            fil(z,rfog);
        }
    }//*/
    n++;
    ll pos=x[0];
    cout << pos << '\n';
    For(i,1,n)
    {
        pos+=x[res[i-1]+1]-x[res[i-1]];
        cout << pos << '\n';
    }
}    
