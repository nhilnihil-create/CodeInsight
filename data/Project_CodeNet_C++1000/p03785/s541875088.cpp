#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

int main(){

  int N, C, K, T;
  cin >> N >> C >> K;
  vector<int> vec(N);

  for (int i = 0; i < N; i++){
    cin >> T;
    vec.at(i) = T;
  }
  sort(vec.begin(), vec.end());
  int ans = 1, sum = 1, memo=vec[0];

  for (int i = 1; i < N; i++) {
    if(sum == C || memo+K < vec[i]){ // バスに全員乗り、かつ、memo+Kが時刻より大きい場合
      ans++;
      sum = 1;
      memo = vec[i];
    }
    else sum++;
  }
  cout << ans << endl;
  
  return 0;
}