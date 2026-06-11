#include<bits/stdc++.h>
#define lld long long int
#define ld long double
#define mod 1000000007
#define modd 998244353
#define all(v) v.begin(),v.end()
#define rep(i,a,b)	for(lld i=a;i<=b;i++)
#define repr(i,a,b) for(lld i=a;i>=b;i--)
#define ar array
#define pb push_back
#define mp make_pair
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
lld n,m;
lld arr[300000];
lld brr[300000];
lld fastpower(lld x, unsigned lld y, lld p)
{
    lld res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
int main()
{
     ios;
     lld TESTS,q,a,s,b,l,r,c,k,p,h,w,d,x,y,z,xs,ys,t;
     TESTS=1;
     memset(brr,-1,sizeof(brr));
     //cin>>TESTS;
     while(TESTS--)
     {
         cin>>n;
         ar<lld,2> pts;
         //lld cur=0;
         rep(i,0,n){
             cin>>arr[i];
             if (brr[arr[i]]!=-1){
                pts[1]=i;
                pts[0]=brr[arr[i]];
             }
             brr[arr[i]]=i;
         }
         if (n==1){
            cout<<"1\n1";
            return 0;
         }
         x=pts[0];
         y=n-pts[1];
         //cout<<pts[0]<<" "<<pts[1]<<"\n";
         x=x+y;
         ar<lld,2> prev;
         prev[0]=1;
         prev[1]=0;
         ar<lld,4> cur;
         cur[0]=n-1;
         cur[1]=1;
         cur[2]=x;
         //if (n-1==x)while(true);
         cur[3]=1;
         lld val=1;
         rep(i,1,n-1){
             lld now=(prev[0]*cur[0])%mod;
             now*=fastpower(cur[1],mod-2,mod);
             now%=mod;
             lld ret=(2*prev[0])%mod;
             ret+=now;
             ret%=mod;
             ret+=prev[1];
             ret%=mod;
             if (i-1<=x){
                 ret+=mod-val;
                 ret%=mod;
                 val*=cur[2];
                 val%=mod;
                 val*=fastpower(cur[3],mod-2,mod);
                 val%=mod;
             }
             cur[0]--;
             cur[1]++;
             cur[2]--;
             cur[3]++;
             prev[1]=prev[0];
             prev[0]=now;
             cout<<ret<<"\n";
         }
        if (x!=n-1)
         cout<<n+1<<"\n"<<1;
         else cout<<n<<"\n"<<1;
     }
    return 0;
}
