#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int N, K, multiply;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> K;

  multiply = K;
  for (int i = 0; i < N - 1; i++) {
    multiply *= K - 1;
  }
  cout << multiply << endl;
}