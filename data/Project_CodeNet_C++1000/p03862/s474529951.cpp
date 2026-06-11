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
    ll T=1,t,n,m,x,k,i,j;
    // cin>>T;
    while(T--)
    {
        cin>>n>>x;
        ll a[n];
        FOR(i,0,n)  cin>>a[i];
        ll ans = 0;
        if(a[0]>x){
            ans = a[0]-x;
            a[0]=x;
        }
        FOR(i,1,n)
        {
            if((a[i]+a[i-1])>x){
                ans += a[i] - x + a[i-1];
                a[i] = x-a[i-1];
            }
        }
        cout<<ans<<endl;
    }
}