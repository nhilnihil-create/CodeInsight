#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> bou(N);
    for (int i = 0; i < N; i++) {
      cin >> bou.at(i);
    }
  std::sort(bou.begin(), bou.end(), std::greater<int>() );
  int M = 0;
  for (int i=0; i<K; i++){
    M = M + bou.at(i);
  }
  cout << M << endl;
}