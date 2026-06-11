#include <bits/stdc++.h>
using namespace std;

int main() {
  int sum = 0;
  vector<int> vec(3);
  for(int i = 0; i < 3; i++){
    cin >> vec.at(i);
  }
  
  // ソート
  sort(vec.begin(), vec.end());
  
  // 選択本数分計算
  for(int i = 0; i < 2; i++){
    sum += vec.at(i);
  }
  
  cout << sum;
}
