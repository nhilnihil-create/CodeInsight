#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N,M;
  cin >> N >> M;
  ll INF = 10000000000;
  vector<vector<ll>> dp(N, vector<ll>(N, INF));

  for(int i = 0; i < N; i++){
    dp.at(i).at(i) = 0;
  }

  map<pair<int,int>, ll> m;
  map<pair<int,int>, bool> check;
  for(int i = 0; i < M; i++){
    int a,b;
    ll c;
    cin >> a >> b >> c;
    a--;
    b--;
    dp.at(a).at(b) = c;
    dp.at(b).at(a) = c;

    if(a > b) swap(a,b);

    m[make_pair(a,b)] = c;
    check[make_pair(a,b)] = false;
  }

  // ワーシャルフロイド
  for(int k = 0; k < N; k++){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }

  for(int i = 0; i < N-1; i++){
    for(auto e: check){
      if(e.second) continue;
      
      ll length = m[e.first];
      int start = e.first.first;
      int end = e.first.second;

      if(dp[i][start] == dp[i][end] + length) check[e.first] = true;
      if(dp[i][end] == dp[i][start] + length) check[e.first] = true;
    }
  }

  int ans = 0;
  for(auto x: check){
    if(!x.second) ans++;
  }
  cout << ans << endl;

}
