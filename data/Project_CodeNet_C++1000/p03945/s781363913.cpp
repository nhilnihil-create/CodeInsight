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
    ll T=1,t,n,m,q,ans=0,i,j;
    // cin>>T;
    while(T--)
    {
        string st;
        char cur;
        cin>>st;
        n = st.length();
        cur = st[0];
        FOR(i,1,n)
        {
            if(st[i]!=cur)
            {
                ans++;
                cur = st[i];
            }
        }
        cout<<ans<<endl;
        
    }
}