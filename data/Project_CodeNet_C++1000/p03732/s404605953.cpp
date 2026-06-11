#include <bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
  lint N, W; cin >> N >> W;
  lint w, v; cin >> w >> v;
  vector<vector<lint> > data(4, vector<lint> ());
  data[0].push_back(v);
  for(int i = 1; i < N; i++){
    lint w1, v1; cin >> w1 >> v1;
    data[w1 - w].push_back(v1);
  }
  for(int i = 0; i < 4; i++) sort(data[i].begin(), data[i].end(), greater<lint>());
  vector<lint> sum1(data[0].size()+1, 0), sum2(data[1].size()+1, 0), sum3(data[2].size()+1, 0), sum4(data[3].size()+1, 0);
  for(int i = 0; i < data[0].size(); i++) sum1[i + 1] += sum1[i] + data[0][i];
  for(int i = 0; i < data[1].size(); i++) sum2[i + 1] += sum2[i] + data[1][i];
  for(int i = 0; i < data[2].size(); i++) sum3[i + 1] += sum3[i] + data[2][i];
  for(int i = 0; i < data[3].size(); i++) sum4[i + 1] += sum4[i] + data[3][i];
  
  lint ans = 0;
  for(lint c1 = 0; c1 < sum1.size(); c1++){
    for(lint c2 = 0; c2 < sum2.size(); c2++){
      for(lint c3 = 0; c3 < sum3.size(); c3++){
        for(lint c4 = 0; c4 < sum4.size(); c4++){
          lint sum = w * c1 + (w + 1) * c2 + (w + 2) * c3 + (w + 3) * c4;
          if(sum > W) continue;
          lint ans1 = sum1[c1] + sum2[c2] + sum3[c3] + sum4[c4];
          ans = max(ans, ans1);
        }
      }
    }
  }
  cout << ans << endl;
}