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

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int N, M, X[int(1e5 + 5)];
int Count[int(1e5 + 5)], Same[int(1e5 + 5)];

int main(){
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) scanf("%d", X + i);
  sort(X, X + N);

  int cnt = 1;
  for (int i = 0; i < N; i++){
    if (X[i] == X[i + 1]){
      cnt++;
      continue;
    }
    Count[X[i] % M] += cnt;
    Same[X[i] % M] += cnt / 2;
    cnt = 1;
  }

  int ans = Count[0] / 2;
  if (M % 2 == 0) ans += Count[M / 2] / 2;

  for (int i = 1; i < (M + 1) / 2; i++){
    int now = min(Count[i], Count[M - i]);
    Count[i] -= now; Count[M - i] -= now;
    now += min(Same[i], Count[i] / 2);
    now += min(Same[M - i], Count[M - i] / 2);
    ans += now;
  }
  printf("%d\n", ans);

  return 0;
}
