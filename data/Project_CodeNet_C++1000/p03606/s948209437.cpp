#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, ans;
  cin >> N;
  ans=0;
  vector<int> l(N);
  vector<int> r(N);
  for (int i=0; i<N; i++) {
    cin >> l.at(i) >> r.at(i);
  }
  for (int j=0; j<N; j++) {
    ans=ans+r.at(j)-l.at(j)+1;
  }
  cout << ans << endl;
}