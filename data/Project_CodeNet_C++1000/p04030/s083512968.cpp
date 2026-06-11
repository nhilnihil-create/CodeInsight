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
    ll T=1,t,n,m,q,k,i,j;
    // cin>>T;
    while(T--)
    {
        string st;
        cin>>st;
        vector<char> ans(st.size());
        j=0;
        FOR(i,0,st.size())
        {
          if(st[i]=='B'){
            if(j>0)
              j--;
          }
          else
            ans[j++]=(char)st[i];
        }
        FOR(i,0,j)cout<<ans[i];
        cout<<endl;
    }
}