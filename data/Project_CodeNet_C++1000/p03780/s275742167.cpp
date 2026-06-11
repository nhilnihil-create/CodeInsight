#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n, c;
  cin >> n >> c;
  vector<int> v;
  for (int i = 0; i < n; i++){
    int d;
    cin >> d;
    if (d < c) v.push_back(d);
  }
  sort(v.begin(), v.end());
  int prev = 0;
  int count = 0;
  for (int i = 0; i < v.size(); i++) {
    if (prev == v[i]) count++;
    else {
      prev = v[i];
      vector<bool> b(c+1, false);
      bool flag = false;
      b[0] = true;
      for (int j = i + 1; j < v.size(); j++){
        for (int k = c-v[j]; k >= 0; k--) {
          if (b[k]) {
            int w = k+v[j];
            b[w] = true;
            //cout << k  << "\t" << w << endl;
            if (w >= c - v[i] && w < c) {
              flag = true;
              break;
            }
          }
        }
      }
      if (flag) break;
      else count++;
    }
  }
  cout << count << endl;
  return 0;
}
