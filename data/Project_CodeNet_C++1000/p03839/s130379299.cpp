//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <time.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
 
const ll inf = 1e9 + 7;
const ll Mod = 998244353;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

int N, K;
ll A[int(1e5 + 5)], L[int(1e5 + 5)], R[int(1e5 + 5)], sum[int(1e5 + 5)];

int main(){
  scanf("%d%d", &N, &K);
  for (int i = 1; i <= N; i++) scanf("%lld", A + i);

  for (int i = 1; i <= N; i++){
    sum[i] = sum[i - 1] + A[i];
    L[i] = L[i - 1] + max(0ll, A[i]);
  }
  for (int i = N; i >= 0; i--){
    R[i] = R[i + 1] + max(0ll, A[i]);
  }

  ll ans = 0;
  for (int i = 0; i + K <= N; i++){
    ll now = max(0ll, sum[i + K] - sum[i]);
    now += L[i] + R[i + K + 1];
    ans = max(ans, now);
  }
  printf("%lld\n", ans);
  return 0;
}
