#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
int main() {
  int N,W; cin>>N>>W;
  vi wgt(N); vi value(N);
  rep(i,N) {cin>>wgt[i]; cin>>value[i];}
  vi w(4);
  rep(i,4) w[i] = wgt[0]+i;
  vvi v(4,vi(0));
 
  rep(i,N){
    if(wgt[i] == w[0]) v[0].push_back(value[i]);
    else if(wgt[i] == w[1] ) v[1].push_back(value[i]);
    else if(wgt[i] == w[2] ) v[2].push_back(value[i]);
    else if(wgt[i] == w[3] ) v[3].push_back(value[i]);
  }
  rep(i,4) {
    sort(all(v[i]),greater<int>());
    rep2(j,1,(int)v[i].size()) v[i][j] += v[i][j-1]; 
    v[i].insert(v[i].begin(),0);
  }

  int w0max = W/w[0];
  int ans =0;  
  for(int i= w0max; i>=0; i--){
    rep(j, (int)v[1].size()){
      if (i*w[0]+j*w[1] > W) break;
      rep(k,(int)v[2].size()){
      if (i*w[0]+j*w[1]+k*w[2] > W) break;
        rep(l,(int)v[3].size()){
          if (i*w[0]+j*w[1]+k*w[2]+l*w[3] > W) break;
  	      ans = max(ans, v[0][i]+v[1][j]+v[2][k]+v[3][l]);
        }
      }
    }
  }
  cout << ans << endl;
}
