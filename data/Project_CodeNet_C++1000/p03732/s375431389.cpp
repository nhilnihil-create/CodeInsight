#include <bits/stdc++.h>
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define e_b emplace_back
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
using namespace std;
using ll = long long;
using ld = long double;
template<class T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N;
  ll W;
  cin >> N >> W;
  vector<ll> w(N);
  vector<int> v(N);
  for(int i=0;i<N;i++)  cin >> w.at(i) >> v.at(i);

  vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(N+1,vector<int>(3*(N+1),0)));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      for(int k=0;k<3*N;k++){
        chmax(dp.at(i+1).at(j).at(k),dp.at(i).at(j).at(k));
        chmax(dp.at(i+1).at(j+1).at(k+w.at(i)-w.at(0)),dp.at(i).at(j).at(k)+v.at(i));
      }
    }
  }
  int ans=0;
  for(int j=0;j<N+1;j++){
    for(int k=0;k<3*(N+1);k++){
      if(j*w.at(0)+k>W) continue;
      chmax(ans,dp.at(N).at(j).at(k));
    }
  }
  cout << ans << endl;

  return 0;
}