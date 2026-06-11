#include<bits/stdc++.h>

#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define Yes(hoge) cout<<((hoge)?"Yes":"No")<<endl;
#define YES(hoge) cout<<((hoge)?"YES":"NO")<<endl;
using namespace std;
int main(){
  ll n,m;cin>>n>>m;
  ll minx=llINF,maxx=-llINF,miny=llINF,maxy=-llINF;
  ll x[n+10]={};
  ll y[m+10]={};
  ll rui[m+10]={};
  for(int i=0;i<n;i++){
    cin>>x[i];
  }
  for(int i=0;i<m;i++){
    cin>>y[i];
    if(i!=0)
      rui[i]=rui[i-1]+y[i]-y[i-1];
  }
  ll ans=0;
  ll sum=0;
 
  int now=m-1;
  int kake=m-2;
  for(int i=1;i<=m/2;i++){
    sum=(sum+(((y[i]-y[i-1])%MOD)*(m-i)%MOD)*i%MOD)%MOD;
    now=(now+kake)%MOD;
    kake--;
  }
  for(int i=m-1;i>m/2;i--){
    sum=(sum+(((y[i]-y[i-1])%MOD)*i%MOD)*(m-i)%MOD)%MOD;
   now=(now+kake)%MOD;
    kake--;
  }
  now=n-1;
  kake=n-2;
  for(int i=1;i<=n/2;i++){
    ans=(ans+((((x[i]-x[i-1])*sum%MOD)*(n-i)%MOD)*i%MOD)%MOD)%MOD;
   now=(now+kake)%MOD;
    kake--;
  }
  now=n-1;
  kake=n-2;
  for(int i=n-1;i>n/2;i--){
    ans=(ans+((((x[i]-x[i-1])*sum%MOD)*i%MOD)*(n-i)%MOD)%MOD)%MOD;
   now=(now+kake)%MOD;
    kake--;
  }
  cout<<ans<<endl;
  return 0;
}
