#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<vector<ll>> v;
vector<vector<ll>> comb(ll n){
  for(int i=0; i<v.size(); i++){
    v[i][0]=1;
    v[i][i]=1;
  }
  for(int j=1; j<v.size(); j++){
    for(int k=1; k<j; k++){
      v[j][k]=(v[j-1][k-1]+v[j-1][k]);
    }
  }
  return v;
}
int main(){
  ll N,A,B,V; cin>>N>>A>>B;
  v.assign(N+1,vector<ll>(N+1,0));  
  vector<ll>Z(N);
  for(int i=0; i<N; i++){cin>>V; Z[i]=V;}
  sort(Z.begin(), Z.end());
  ll a=upper_bound(Z.begin(), Z.end(), Z[N-A])-lower_bound(Z.begin(), Z.end(), Z[N-A]);
  ll b=Z.end()-upper_bound(Z.begin(), Z.end(), Z[N-A]);
  if(Z[N-1]!=Z[N-A]) B=A;
  double ans=0; ll num=0;
  for(int i=0; i<A; i++) ans+=Z[N-1-i];
  ans/=A;
  comb(N);
  for(int i=A-b; i<=B-b; i++){
    num+=v[a][i];
  }
  cout<<fixed<<setprecision(10)<<ans<<endl;
  cout<<fixed<<setprecision(0)<<num<<endl;
}