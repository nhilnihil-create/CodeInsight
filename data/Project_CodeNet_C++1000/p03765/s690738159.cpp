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

int main(){
  string S, T;
  cin >> S >> T;

  ll DP_S[S.length() + 1][2];
  DP_S[0][0] = 0; DP_S[0][1] = 0;
  for (int i = 0; i < S.length(); i++){
    for (int j = 0; j < 2; j++){
      DP_S[i + 1][j] = DP_S[i][j];
    }
    
    if (S[i] == 'A') DP_S[i + 1][0]++;
    else DP_S[i + 1][1]++;
  }

  int DP_T[T.length() + 1][2];
  DP_T[0][0] = 0; DP_T[0][1] = 0;
  for (int i = 0; i < T.length(); i++){
    for (int j = 0; j < 2; j++){
      DP_T[i + 1][j] = DP_T[i][j];
    }
    
    if (T[i] == 'A') DP_T[i + 1][0]++;
    else DP_T[i + 1][1]++;
  }  

  int Q; cin >> Q;
  vector <bool> ans(Q);
  for (int i = 0; i < Q; i++){
    int A, B, C, D; cin >> A >> B >> C >> D;
    A--; C--;

    int S_A = DP_S[B][0] - DP_S[A][0];
    int S_B = DP_S[B][1] - DP_S[A][1];

    int T_A = DP_T[D][0] - DP_T[C][0];
    int T_B = DP_T[D][1] - DP_T[C][1];

    int now = (S_A - S_B) - (T_A - T_B);
    if (now % 3 == 0) ans[i] = true;
  }
  
  for (int i = 0; i < Q; i++){
    if (ans[i] == true) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  
  return 0;
}
