#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using pii = pair<long, long>;
#define fix10 cout << fixed << setprecision(10);
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define MOD 1000000007

int main(){
  int n;
  long W;
  cin >> n >> W;
  vector<vector<long>> V(4);
  long min_w;
  rep(i,n){
    int w,v;
    cin >> w >> v;
    if(i == 0) min_w = w;
    w -= min_w;
    V.at(w).push_back(v);
  }
  rep(i,4){
    sort(V.at(i).begin(),V.at(i).end(),greater<long>());
    rep(j,V.at(i).size()-1){
      V.at(i).at(j+1) += V.at(i).at(j);
    }
    reverse(V.at(i).begin(),V.at(i).end());
    V.at(i).push_back(0);
    reverse(V.at(i).begin(),V.at(i).end());
  }
  vector<pii> data;
  rep(i,V.at(0).size()){
    rep(j,V.at(1).size()){
      rep(k,V.at(2).size()){
        rep(l,V.at(3).size()){
          long w = i*min_w + j*(min_w+1) + k*(min_w+2) + l*(min_w+3);
          long v = V.at(0).at(i) + V.at(1).at(j) + V.at(2).at(k) + V.at(3).at(l);
          data.push_back(pii(w,v));
        }
      }
    }
  }
  long ans = 0;
  rep(i,data.size()){
    long w = data.at(i).first;
    long v = data.at(i).second;
    if(w <= W) ans = max(ans,v);
  }
  cout << ans << endl;
}
