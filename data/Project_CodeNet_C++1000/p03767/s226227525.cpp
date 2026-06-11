#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

int main(){
  int N, a;
  cin >> N;
  long ans = 0;
  vector<int> vec(N*3);
  for(int i = 0; i < N*3; i++){
    cin >> a;
    vec.at(i) = a;
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());

  int x = 0;
  for (int i = 1; i <= N; i++) {
    x = 2*i-1; // 2〜2N番目までの数をみる
    ans += vec.at(x);
  }

  cout << ans << endl;

  return 0;
}
