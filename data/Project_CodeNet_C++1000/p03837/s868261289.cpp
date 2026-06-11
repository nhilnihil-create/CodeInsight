#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = 1e18+1;
ll MOD=1e9+7;

int main(){
  int N,M;
  cin>>N>>M;
  int d[100][100] = {0};
  for(int i(0);i<100;i++){
    for(int j(0);j<100;j++){
      if(i == j) continue;
      d[i][j] = INFint;
    }
  }
  int a[10000],b[10000],c[10000];
  for(int i(0);i<M;i++){
    cin>>a[i]>>b[i]>>c[i];
    a[i]--;
    b[i]--;
    d[a[i]][b[i]] = c[i];
    d[b[i]][a[i]] = c[i];
  }
  for (int k = 0; k < N; k++){       // 経由する頂点
    for (int i = 0; i < N; i++) {    // 始点
      for (int j = 0; j < N; j++) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  int ans(0);
  for(int i(0);i<M;i++){
    if(d[a[i]][b[i]] != c[i]){
      ans++;
    }
  }
  cout << ans << endl;
}
