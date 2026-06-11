#include <bits/stdc++.h>
using namespace std;
int main () {
  long N, MA, MB;
  cin >> N >> MA >> MB;
  vector<vector<long>> data(401, vector<long> (401, INT_MAX));
  data.at(0).at(0) = 0;
  long a, b, c;
  for(int i = 0; i < N; i++){
    cin >> a >> b >> c;
    for(int j = 390; j >= 0; j--){
      for(int k = 390; k >= 0; k--){
        if(data.at(j).at(k) != INT_MAX){
          data.at(j + a).at(k + b) = min(data.at(j + a).at(k + b), data.at(j).at(k) + c);
        }
      }
    }
  }
  long sub = 1, ans = INT_MAX;
  while(sub * MA <= 400 && sub * MB <= 400){
    ans = min(ans, data.at(sub * MA).at(sub * MB));
    sub++;
  }
  cout << (ans == INT_MAX?-1:ans) << endl;
  return 0;
}