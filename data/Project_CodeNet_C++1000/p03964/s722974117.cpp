#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define INF 1000000000000
#define MOD 10000007
typedef long long ll;
//

int main(){
   ll n;cin>>n;
   vector<vector<int>> v;
   ll ans=INF;
   ll t,a;
   rep(i,n){
      vector<int> vv;
      int a,b;cin>>a>>b;
      vv.push_back(a);
      vv.push_back(b);
      v.push_back(vv);
   }
   t=v[0][0];
   a=v[0][1];
   ans=t+a;
   if(n==1) {
      cout<<ans<<endl;
      return 0;
   }else{
      rep(i,n-1){
      ll c=max(t/v[i+1][0],a/v[i+1][1]);
      if(c*v[i+1][0]<t||c*v[i+1][1]<a)c++;
      t=c*v[i+1][0];
      a=c*v[i+1][1];
      ans=t+a;
      }
   }
  cout<<ans<<endl;
}