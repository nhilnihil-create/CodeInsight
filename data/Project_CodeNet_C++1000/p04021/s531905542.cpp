/*
Nahid Hossain
Jahangirnagar University
Roll:54
*/
#include<bits/stdc++.h>
#include<string.h>
#define ll long long
#define pf printf
#define sf scanf
#define ff first
#define ss second
#define clr clear()
#define sz size()
#define pb push_back
#define mk make_pair
#define pi acos(-1)
#define inf 2000000000000000000
#define mod 1000000007
#define ull unsigned long long int
#define f(i,k,n) for(i=k;i<n;i++)
#define fr(i,n,k) for(i=n;i>=k;i--)
#define ent(a) scanf("%lld",&a)
#define ent2(a,b) scanf("%lld%lld",&a,&b)
#define ent3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define mem(a) memset(a,0,sizeof(a))
#define vec(v,s) vector<ll>v[s]
#define arr(a,s) ll a[s];
//knight and king//
int dr[]= {2,2,-2,-2,1,-1,1,-1};
int dc[]= {1,-1,1,-1,2,2,-2,-2};
int dr1[]= {0,0,1,1,1,-1,-1,-1};
int dc1[]= {1,-1,1,0,-1,0,1,-1};
int dr2[]= {0,0,1,-1};
int dc2[]= {1,-1,0,0};
////////////////////////////
using namespace std;
#define ma 200005
ll a[ma],b[ma];





int main()
{
    ll n,i,j;
    while(cin>>n)
    {
        vector<pair<ll,ll> >v;

        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            v.pb(mk(a[i],i));
            b[i]=a[i];
        }

        ll ans=0;

        sort(v.begin(),v.end());

        for(i=0;i<v.sz;i++)
        {
            ll x=i+1;
            ll y=v[i].ss;
            if(y%2==0&&x%2==1)ans++;
        }

        cout<<ans<<endl;

    }
    return 0;
}
