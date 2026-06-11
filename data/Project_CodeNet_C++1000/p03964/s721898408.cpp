#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define M 1000000007
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define f first
#define s second
#define b begin
#define e end
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(i=a;i<b;i++)
#define RFOR(i,a,b) for(i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define itfr(it,x) for(it=x.begin();it!=x.end();it++)
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main()
{
    flash;
    //sieve();
    ll T=1,n,m,k,i;
    while(T--)
    {
        cin>>n;
        ll t[n],a[n],x,y;
        FOR(i,0,n)  cin>>t[i]>>a[i];
        m = 1; k = 1;
        FOR(i,0,n)
        {
            ll z1 = ceil((long double)m/t[i]);
            ll z2 = ceil((long double)k/a[i]);
            ll z = max(z1,z2);
            x = t[i]*z-m;
            y = a[i]*z-k; 
            // cout<<x<<" "<<y<<endl;
            m +=x;
            k +=y;
        }
        ll ans=m+k;
        cout<<ans<<endl;
    }
}