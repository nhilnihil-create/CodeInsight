#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
#include<functional>
#include<stack>
#include<tuple>
#include<cassert>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using P = pair<int, int>;

int main() {
  int N, K;
  int l[50];
  cin >> N >> K;
  rep(i, N) {
    cin >> l[i];
  }
  sort(l, l+N);
  int ans = 0;
  for(int i = N-1; i >= N - K; i--) {
    ans += l[i];
  }
  cout << ans << endl;
  return 0;
}