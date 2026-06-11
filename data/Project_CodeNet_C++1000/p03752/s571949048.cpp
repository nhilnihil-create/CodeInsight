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
  int K, N; cin >> N >> K;
  ll A[N];
  for (int i = 0; i < N; i++) cin >> A[i];

  int Order[N] = {};
  for (int i = 0; i < K; i++) Order[i] = 1;
  sort(Order, Order + N);

  ll ans = 1e18;
  do{
    ll now = 0, Highest = A[0];
    for (int i = 1; i < N; i++){
      if (Order[i] == 1 && A[i] <= Highest){
        now += Highest - A[i] + 1;
        Highest++;
      }else{
        Highest = max(Highest, A[i]);
      }
    }
    ans = min(ans, now);
  }while (next_permutation(Order, Order + N));
  cout << ans << endl;
  
  return 0;
}
