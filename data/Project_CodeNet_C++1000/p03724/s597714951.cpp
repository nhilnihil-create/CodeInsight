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

int main(){
  int N, M; cin >> N >> M;
  int cnt[N] = {};
  for (int i = 0; i < M; i++){
    int A, B; scanf("%d%d", &A, &B);
    A--; B--;
    cnt[A]++; cnt[B]++;
  }

  for (int i = 0; i < N; i++){
    if (cnt[i] % 2 != 0){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  
  return 0;
}
