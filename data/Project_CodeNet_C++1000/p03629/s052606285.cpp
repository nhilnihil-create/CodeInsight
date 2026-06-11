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
lld dp[300000];
ar<lld,26> nex[300000];
string st;
string ans;
int main()
{
     ios;
     lld TESTS,q,a,s,b,l,r,c,k,p,h,w,d,x,y,z,xs,ys,t;
     TESTS=1;
     //cin>>TESTS;
     //memset(nex,-1,sizeof(nex));
     while(TESTS--)
     {
         cin>>st;
         n=st.size();
         ar<lld,26> cur;
         rep(i,0,25)cur[i]=-1;
         repr(i,n-1,0){
             cur[st[i]-'a']=i;
             nex[i]=cur;
         }
         dp[n]=1;
         repr(i,n-1,0){
            dp[i]=1e15;
            rep(j,0,25){
                if (nex[i][j]==-1){
                    dp[i]=1;
                    continue;
                }
                dp[i]=min(dp[i],dp[nex[i][j]+1]+1);
            }
         }
         lld i=0;
       //  cout<<dp[0]<<"\n";
         while(i<n){
            char ch='a';
            rep(j,0,25){
                if (nex[i][j]==-1){
                    ch+=j;
                    ans.pb(ch);
         //           cout<<i<<" "<<j<<"\n";
                    i=n+4;
                    break;
                }
                if (dp[nex[i][j]+1]+1==dp[i]){
                    ch+=j;
                    i=nex[i][j]+1;
           //         cout<<i<<" "<<j<<"\n";
                    ans.pb(ch);
                    break;
                }
            }
            //printf("%lld\n",i);
         }
         cout<<ans;
     }
    return 0;
}
