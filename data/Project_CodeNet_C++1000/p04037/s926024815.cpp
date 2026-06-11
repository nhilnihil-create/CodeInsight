#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int LL;
typedef int ll;
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
 
const ll M=2e5+5,LG=19,SM=2000+5,inf=1e9+1;
ll mod=1e9+7;
 
ll n;
ll a[M]; 
str z[2]={"First","Second"};
void ret(ll x)
{
    cout << z[x];
    exit(0);
}

int main()
{
	ios::sync_with_stdio(0);
    cin >> n;
    For(i,0,n) cin >> a[i];
    sort(a,a+n,[](ll i,ll j){ return i>j; });
    a[n]=-inf;
    ll x=0;
    For(i,0,n)
    {
        if (a[i]>i)
            x=i;
        else
            break;
    }
    if ((a[x]-x)%2==0) ret(0);
    if (a[x+1]<x+1) ret(1);
    ll y=x+1;
    while (a[y]==a[x+1]) y++;
    ret((y-x)%2);   
}