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

int N, Q;
ll X[int(1e5 + 5)], L;
int Table[40][int(1e5 + 5)];
ll Bit[40];

int main(){
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%lld", X + i);
  scanf("%d", &L);

  int now = 0;
  for (int i = 0; i < N; i++){
    while (now < N - 1){
      if (X[now + 1] - X[i] > L) break;
      now++;
    }
    Table[0][i] = now;
  }

  Bit[0] = 1;
  for (int i = 1; i < 40; i++){
    Bit[i] = Bit[i-1] * 2;
    for (int j = 0; j < N; j++){
      Table[i][j] = Table[i-1][Table[i-1][j]];
    }
  }

  scanf("%d", &Q);
  while (Q > 0){
    Q--;
    int A, B; scanf("%d%d", &A, &B);
    A--; B--;
    if (A > B) swap(A, B);

    ll ans = 0; int now = A;
    while (now < B){
      if (Table[0][now] == B){
        ans++; now = B;
        break;
      }
      for (int i = 1; i < 40; i++){
        int next = Table[i][now];
        if (next >= B){
          now = Table[i-1][now];
          ans += Bit[i-1];
          break;
        }
      }
    }
    printf("%lld\n", ans);
  }

  return 0;
}
