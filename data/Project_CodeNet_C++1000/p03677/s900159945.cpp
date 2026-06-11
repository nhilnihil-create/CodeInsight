#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<deque>
#include<map>
#include<bitset>
#include<math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define REP(i,m,n) for(ll i=m;i<(ll)(n);i++)
typedef pair<int,long long> pint;
typedef long long ll;
const ll mod= 1e9+7;
const ll  longinf = 1LL<<60;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};




int main(){
  int n,m;
  cin>>n>>m;
  ll a[n];
  rep(i,n){
    cin>>a[i];
    a[i]--;
    }
  ll b[2*m+1],c[2*m+1];
  rep(i,2*m+1)b[i]=c[i]=0;
  ll ans=0;
  rep(i,n-1){
    if(a[i]<a[i+1]){
      ans+=a[i+1]-a[i];
      b[a[i]+2]++;
      b[a[i+1]+1]--;
      c[a[i+1]+1]-=a[i+1]-a[i]-1;
      }
    else{
      int x=a[i+1]+m;
      ans+=x-a[i];
      b[a[i]+2]++;
      b[x+1]--;
      c[x+1]-=x-a[i]-1;
      }
    }
  rep(i,2*m)b[i+1]+=b[i];
  rep(i,2*m+1)c[i]+=b[i];
  rep(i,2*m)c[i+1]+=c[i];
  rep(i,m)c[i]+=c[i+m];
  ll ma=0;
  rep(i,m)ma=max(c[i],ma);
  cout<<ans-ma<<endl;     
  return 0;
  }