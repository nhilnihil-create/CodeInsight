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
 
const ll nmax = 1e9 + 7;
const ll Mod = 998244353;
const double PI = 2 * asin(1);

int N, A, X[51];
ll DP[51][51][2501];

int main(){
  cin >> N >> A;
  for (int i = 1; i <= N; i++) cin >> X[i];
  DP[0][0][0] = 1;

  for (int i = 1; i <= N; i++){

    for (int j = 0; j <= N; j++){
      for (int k = 0; k <= A * N; k++){
        DP[i][j][k] = DP[i-1][j][k];
      }
    }

    for (int j = 0; j < N; j++){
      for (int k = 0; k <= A * N; k++){
        DP[i][j + 1][k + X[i]] += DP[i - 1][j][k];
      }
    }
  }
  
  ll ans = 0;
  for (int j = 1; j <= N; j++){
    ans += DP[N][j][j * A];
  }
  cout << ans << endl;
  
  return 0;
}
