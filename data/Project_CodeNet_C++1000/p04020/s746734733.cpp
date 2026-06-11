#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 10007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
  int N; cin>>N;
  vector<ll> A(N+1);
  rep1(i,N)cin>>A.at(i);
  ll res = 0;
  ll tmp = 0;
  for(int i = 1; i <= N; i++){
    tmp += A.at(i);
      //cout<<tmp<<endl;
    if(i!=N&&A.at(i)==0){
      res+=tmp/2;
      tmp = 0;
    }
  }
  res+=tmp/2;
  cout<<res<<endl;
}
