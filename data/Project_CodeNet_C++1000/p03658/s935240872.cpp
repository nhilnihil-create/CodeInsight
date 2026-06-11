#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, K, ans;
  cin >> N >> K;
  ans=0;
  vector<int> l(N);
  for (int i=0; i<N; i++) {
    cin >> l[i];
  }
  sort(l.begin(),l.end());
  reverse(l.begin(),l.end());
  for (int j=0; j<K; j++) {
    ans=ans+l[j];
  }
  cout << ans << endl;
}