#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define pi 3.14159265358979323846264338327950L
using namespace std;

int main() {
  int64_t N, j=0, ans=0;
  cin >> N;
  vector<int64_t> A(N);
  vector<int64_t> B(N);
  for (int64_t i=0; i<N; i++) {
    cin >> A[i];
    B[i]=0;
  }
  sort(A.begin(),A.end());
  if (N==1) {
    B[0]=1;
  }
  else {
    B[0]=1;
    for (int64_t i=1; i<N; i++) {
      if (A[i-1]==A[i]) {
        B[j]++;
      }
      else {
        j++;
        B[j]++;
      }
    }
  }
  for (int64_t i=0; i<N; i++) {
    if (B[i]%2==1) {
      ans++;
    }
  }
  cout << ans << endl;
}