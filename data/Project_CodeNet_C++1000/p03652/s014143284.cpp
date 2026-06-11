#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define rep(i,N) for(int i=0;i<N;i++)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N,M;
  cin>>N>>M;
  vector<vector<int>>A(N,vector<int>(M));
  for(int i=0;i<N;i++)for(int j=0;j<M;j++)cin>>A[i][j];
  for(int i=0;i<N;i++)for(int j=0;j<M;j++)A[i][j]--;
  vector<bool>ng(M,false);
  ll ans=N;
  for(int i=0;i<M-1;i++){
    ll res=0;
    map<int,int>m;
    for(int j=0;j<N;j++){
      for(int k=0;k<M;k++){
        if(!ng[A[j][k]]){
          m[A[j][k]]++;
          break;
        }
      }
    }
    vector<pair<ll,ll>>a;
    for(auto it:m)a.push_back({it.second,it.first});
    ans=min(ans,(*max_element(rng(a))).first);
    ng[(*max_element(rng(a))).second]=true;
  }
  cout<<ans<<endl;
  return 0;
}
