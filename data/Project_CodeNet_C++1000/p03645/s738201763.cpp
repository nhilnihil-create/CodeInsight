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
#define mp make_pair
 
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

int N, M, Dist[int(2e5 + 5)];
vector <int> Graph[int(2e5 + 5)];

int main(){
  scanf("%d%d", &N, &M);
  fill(Dist + 2, Dist + N + 1, -1);
  for (int i = 0; i < M; i++){
    int A, B; scanf("%d%d", &A, &B);
    Graph[A].push_back(B);
    Graph[B].push_back(A);
  }
  queue <int> que; que.push(1);

  while (!que.empty()){
    int Q = que.front(); que.pop();
    for (int i = 0; i < Graph[Q].size(); i++){
      int next = Graph[Q][i];
      if (Dist[next] != -1) continue;
      Dist[next] = Dist[Q] + 1;
      que.push(next);
    }
  }

  if (Dist[N] == 2) printf("POSSIBLE\n");
  else printf("IMPOSSIBLE\n");

  return 0;
}
