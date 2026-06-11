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

ll Cost[1000][1000], Dist[1000];

int main(){
  int N, M; cin >> N >> M;

  fill((ll*)Cost, (ll*)(Cost + N), 1e18);

  for (int i = 0; i < M; i++){
    int A, B; ll C; cin >> A >> B >> C;
    A--; B--; C *= -1;
    Cost[A][B] = C;
  }

  fill(Dist, Dist + N, 1e18);
  Dist[0] = 0;
  bool flag = false;

  for (int k = 0; k < N; k++){
    for (int i = 0; i < N; i++){
      for (int j = 0; j < N; j++){
        if (i == j) continue;
        ll next = Cost[i][j];
        if (Dist[i] != 1e18 && Dist[j] > Dist[i] + next){
          Dist[j] = Dist[i] + next;
          if (k == N - 1 && j == N - 1) flag = true;
        }
      }
    }
  }

  if (flag == true){
    cout << "inf" << endl;
  }else{
    cout << -1 * Dist[N - 1] << endl;
  }

  return 0;
}