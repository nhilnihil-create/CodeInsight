#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, K, ans;
  cin >> N >> K;
  ans=K;
  if (N>=2) {
    for (int i=0; i<N-1; i++) {
      ans=ans*(K-1);
    }
  }
  cout << ans << endl;
}
