#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>
 
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define LLIandI pair<long long int , int>
#define ll long long
 int main(){
     long long int n,m;
     scanf("%lld %lld",&n,&m);
     long long int x[100002],y[100002];
     long long int bx[100002],by[100002];
     rep(i,n){scanf("%lld",&x[i]);if(i>0)bx[i-1]=x[i]-x[i-1];}
     rep(i,m){scanf("%lld",&y[i]);if(i>0)by[i-1]=y[i]-y[i-1];}
     long long int mod=1000000007;
     long long int xans=0,yans=0;
     rep(i,n-1){
         long long int use=(n-1-i)*(i+1);
         xans+=(bx[i]*use)%mod;xans%=mod;
     }
     rep(i,m-1){
         long long int use=(m-1-i)*(i+1);
         yans+=(by[i]*use)%mod;yans%=mod;
     }
     printf("%lld\n",(xans*yans)%mod );
     
 }