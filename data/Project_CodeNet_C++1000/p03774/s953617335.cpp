#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  ll N, M;
  cin >> N >> M;
  
  vector<ll> AX(N), AY(N), BX(M), BY(M);
  for (int i = 0; i < N; i++){
    cin >> AX.at(i) >> AY.at(i);
  }
  for (int i = 0; i < M; i++){
    cin >> BX.at(i) >> BY.at(i);
  }
  
  vector<ll> ans(N);
  for (int i = 0; i < N; i++){
    ll near = 1000000000, pos = 0;
    for (int j = 0; j < M; j++){
      ll dist = abs(AX.at(i) - BX.at(j)) + abs(AY.at(i) - BY.at(j));
      if (near > dist){
        near = dist;
        pos = j;
      }
    }
    
    ans.at(i) = pos + 1;
  }
  
  for (int i = 0; i < N; i++){
    cout << ans.at(i) << endl;
  }
}