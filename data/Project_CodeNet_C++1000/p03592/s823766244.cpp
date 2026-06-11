#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int N, M, K, ans;
  cin >> N >> M >> K;
  ans=0;
  for (int i=0; i<=N; i++) {
    for (int j=0; j<=M; j++) {
      if (i*(M-j)+j*(N-i)==K) {
        ans=ans+1;
      }
    }
  }
  if (ans>0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
