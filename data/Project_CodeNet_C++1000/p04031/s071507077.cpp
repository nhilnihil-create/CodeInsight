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
   int n;cin>>n;
   vector<int> v;
   rep(i,n){
      int a;cin>>a;
      v.push_back(a);
   }
   ll ans=INF;
   FOR(i,-100,100){
      ll t=0;
      rep(j,n){
         t+=(v[j]-i)*(v[j]-i);
      }
      ans=min(ans,t);
   }
   cout<<ans<<endl;
}