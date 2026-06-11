#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int w, h, n;
  cin >> w >> h >> n;
  
  vector<int> x(n), y(n), a(n);
  for (int i = 0; i < n; i++) {
    cin >> x.at(i) >> y.at(i) >> a.at(i);
  }

  vector<vector<int>> data(h, vector<int>(w, 0));
  
  for (int i = 0; i < n; i++) {
    if(a.at(i) == 1){
      for (int j = 0; j < h; j++) {
        for (int k = 0; k < x.at(i); k++) {
          data.at(j).at(k) = 1;
        }
      }
    }
    if(a.at(i) == 2){
      for (int j = 0; j < h; j++) {
        for (int k = x.at(i); k < w; k++) {
          data.at(j).at(k) = 1;
        }
      }
    }
    if(a.at(i) == 3){
      for (int j = h - y.at(i); j < h; j++) {
        for (int k = 0; k < w; k++) {
          data.at(j).at(k) = 1;
        }
      }
    }
    if(a.at(i) == 4){
      for (int j = 0; j < h - y.at(i); j++) {
        for (int k = 0; k < w; k++) {
          data.at(j).at(k) = 1;
        }
      }
    }
  }
  
  int count = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if(data.at(i).at(j) == 0){
        count++;
      }
    }
  }
  
  cout << count << endl;

}
             
 