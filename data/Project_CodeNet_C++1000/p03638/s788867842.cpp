#include <bits/stdc++.h>
using namespace std;
int main () {
  int H, W, N;
  cin >> H >> W >> N;
  vector<vector<long>> ans(H, vector<long> (W));
  vector<long> data(N);
  long pl = 0;
  for(int k = 0; k < N; k++)cin >> data.at(k);
  for(int i = 0; i < H; i++){
    if(i % 2 == 0){
      for(int j = 0; j < W; j++){
        ans.at(i).at(j) = pl + 1;
        data.at(pl)--;
        if(data.at(pl) == 0)pl++;
      }
    } else {
      for(int j = W - 1; j >= 0; j--){
        ans.at(i).at(j) = pl + 1;
        data.at(pl)--;
        if(data.at(pl) == 0)pl++;
      }
    }
  }
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cout << ans.at(i).at(j) << ' ';
    }
    cout << endl;
  }
  return 0;
}