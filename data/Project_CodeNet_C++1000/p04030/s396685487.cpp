#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<long long>lve;
typedef vector<pair<ll,ll> > lvp;
typedef vector<pair<string,ll> > svp;

#define spc        ' '
#define endl       '\n'
#define F          first
#define S          second
#define pp         pop_back
#define pb         push_back
#define mp         make_pair 
#define GCD(x,y)   __gcd(x,y)
#define PI         2*acos(0.0)
#define lb         lower_bound
#define bs         binary_search
#define all(x)     x.begin(),x.end()
#define LCM(x,y)   ((x*y)/__gcd(x,y))
#define btpc       __builtin_popcountll
#define sp(x)      cout<<fixed<<setprecision(x)

const   long long  cs=2e5+5;
const   long long  inf=1e18;
const   long long  mod=1e9+7;
void solve()
{
    ll t,n,m,a,b,c,d,e,i,j,k,x,y,z,cnt=0,cnt1=0;
    bool flag = false;   vector<long long> v,v1;

    string s,s1;
    cin>>s;
    n=s.length();
    for(i=0;i<n;i++)
    {
        if(s[i]!='B') v.pb((s[i]-'0'));
        else {
            if(v.size()>0) v.pp();
        }
    }
    for(i=0;i<v.size();i++)
    {
        cout<<v[i];
    }
    cout<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);

    /*freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);*/

    // ll tc;
    // cin>>tc;
    // while(tc--)
    solve();

    return 0;
}
