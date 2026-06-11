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
ar<lld,2> pref[300000];
int main()
{
     ios;
     lld TESTS,q,a,s,b,l,r,c,k,p,h,w,d,x,y,z,xs,ys,t;
     TESTS=1;
     memset(pref,0,sizeof(pref));
     //cin>>TESTS;
     while(TESTS--)
     {
         cin>>n>>m;
         rep(i,0,n-1)cin>>arr[i],arr[i]--;
        // rep(i,0,m-1)cout<<pref[i][0]<<" "<<pref[i][1]<<"\n";
         lld ans=0;
         rep(i,1,n-1){
            if (arr[i]<arr[i-1]){
                lld dif=m-arr[i-1]-2;
                pref[arr[i-1]+2][0]++;
                pref[0][0]++;
                pref[arr[i]+1][0]--;
                pref[0][1]+=dif;
               // pref[arr[i]+1][1]-=dif;
                pref[arr[i]+1][1]-=(arr[i]-arr[i-1]+m)%m-1;
            }
            else {
                pref[arr[i-1]+2][0]++;
                pref[arr[i]+1][0]--;
                pref[arr[i]+1][1]-=arr[i]-arr[i-1]-1;
            }
            ans+=(arr[i]-arr[i-1]+m)%m;
         }
         lld maxi=0;
        // rep(i,0,m-1) cout<<pref[i][0]<<" "<<pref[i][1]<<"\n";
         rep(i,0,1)rep(j,1,m-1) pref[j][0]+=pref[j-1][0];
         //rep(j,0,m-1) pref[j][0]+=pref[j][1];
         rep(j,1,m-1) pref[j][1]+=pref[j-1][1];
         rep(i,0,m-1){maxi=max(maxi,pref[i][0]+pref[i][1]);}
         //rep(i,0,m-1) cout<<pref[i][0]<<" "<<pref[i][1]<<"\n";
         cout<<ans-maxi;
     }
    return 0;
}
