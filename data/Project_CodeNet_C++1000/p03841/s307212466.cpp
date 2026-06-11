#include <bits/stdc++.h>
 
using namespace std;
 
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
const ll M=1e3+5,LG=19,SM=600+5,inf=1e18+1;
ll mod=1e9+7;

ll x[M];
ll a[M*M];
ll jay[M];
ll n;
ll s=0;
int main()
{
	ios::sync_with_stdio(0);
    cin >> n;
    memset(a,-1,sizeof a);
    For(i,0,n)
    {
        cin >> x[i];
        x[i]--;
        if (a[x[i]]!=-1) RET("No");
        a[x[i]]=i;
    }
    iota(jay,jay+n,0);
    sort(jay,jay+n,
        [](ll i,ll j){ return x[i]<x[j]; });
    For(ii,0,n)
    {
        ll i=jay[ii];
        //ER(i);
        For(j,0,i)
        {
            //ER(j);
            while (a[s]!=-1) s++;
            if (s>x[i]) RET("No");
            a[s]=i;
        }   
    }
    reverse(jay,jay+n);
    s=n*n-1;
    For(ii,0,n)
    {
        ll i=jay[ii];
        //ER(i);
        For(j,0,n-1-i)
        {
            while (s>=0 && a[s]!=-1) s--;
            if (s<x[i]) RET("No");
            a[s]=i;
        }
    }   
    cout << "Yes\n";
    For(i,0,n*n)
        cout << a[i]+1 << ' ';
}    