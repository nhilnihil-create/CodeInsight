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
    ll T=1,n,w,h,i,j;
    // cin>>T;
    while(T--)
    {
        cin>>w>>h>>n;
        ll led=0,leu=h,brl=0,brr=w;
        ll x[n],y[n],a[n];
        FOR(i,0,n)  cin>>x[i]>>y[i]>>a[i];
        FOR(i,0,n)
        {
            if(a[i]==1)
                brl = max(brl,x[i]);
            if(a[i]==2)
                brr = min(brr,x[i]);
            if(a[i]==3)
                led = max(led,y[i]);
            if(a[i]==4)
                leu = min(leu,y[i]);
        }
        if(leu>=led&&brr>=brl){
            ll ans = (leu-led)*(brr-brl);
            cout<<ans<<endl;
        }
        else
            cout<<0<<endl;
    }
}