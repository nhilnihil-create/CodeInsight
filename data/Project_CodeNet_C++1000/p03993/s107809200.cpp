#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int N, ans;
  cin >> N;
  ans=0;
  vector<int> a(N);
  for (int i=0; i<N; i++) {
    cin >> a[i];
  }
  for (int j=0; j<N; j++) {
    if (a[a[j]-1]==j+1) {
      ans=ans+1;
    }
  }
  cout << ans/2 << endl;
}