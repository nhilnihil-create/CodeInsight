#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

int main(){
  int N, K, l;
  cin >> N >> K;
  int ans = 0;
  vector<int> vec(N);

  for (int i = 0; i < N; i++){
    cin >> l;
    vec.at(i) = l;
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());

  for (int i = 0; i < K; i++){
    ans += vec.at(i);
  }

  cout << ans << endl;
  return 0;
}
