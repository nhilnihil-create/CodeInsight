#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N; cin >> N;
  vector<vector<ll>> v(N, vector<ll>(N, 0));
  vector<vector<ll>> w(N, vector<ll>(N, 0));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> v[i][j];
    }
  }

  bool flg = true;
  for(int k = 0; k < N; k++){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        if(v[i][j] > v[i][k] + v[k][j]){
          flg = false;
          break;
        }
        if(w[i][j] == 0 && v[i][j] == v[i][k] + v[k][j] && k != j && k != i){
          w[i][j] = 1; // ijの辺はなくてもいい
        }
      }
      if(!flg) break;
    }
    if(!flg) break;
  }

  if(flg){
    ll ans = 0;
    // todo
    for(int i = 0; i < N-1; i++){
      for(int j = i+1; j < N; j++){
        // cerr << i << " " << j << " " << w[i][j] << " " << v[i][j] << endl;
        if(w[i][j] == 0){
          ans += v[i][j];
        }
      }
    }
    cout << ans << endl;
  } else { 
    cout << -1 << endl;
  }
}
