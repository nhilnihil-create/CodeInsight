#include <bits/stdc++.h>
using namespace std;
int main () {
  long N, M;
  cin >> N >> M;
  vector<pair<long, long>> data(N);
  for(int i = 0; i < N; i++)data.at(i).first = 1;
  data.at(0).second = 1;
  long x, y;
  for(int i = 0; i < M; i++){
    cin >> x >> y;
    x--;
    y--;
    data.at(x).first--;
    data.at(y).first++;
    if(data.at(x).second == 1){
      if(data.at(x).first == 0)data.at(x).second = 0;
      data.at(y).second = 1;
    }
  }
  long ans = 0;
  for(int i = 0; i < N; i++)if(data.at(i).second == 1)ans++;
  cout << ans << endl;
  return 0;
}
