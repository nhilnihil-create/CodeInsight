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
 
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1ll << 60;
const double PI = 2 * asin(1);

int N, K; ll A[15];

int main(){
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> A[i];


  ll ans = INF;
  for (int i = 0; i < pow(2, N); i++){
    int num = i, cnt = 0;
    ll Cost = 0, Highest = 0;
    for (int j = 0; j < N; j++){
      if (num % 2 != 0){
        cnt++;
        if (Highest < A[j]){
          Highest = A[j];
        }else{
          Cost += Highest - A[j] + 1;
          Highest++;
        }
      }else{
        Highest = max(Highest, A[j]);
      }
      num /= 2;
    }
    if (cnt >= K) ans = min(Cost, ans);
  }
  cout << ans << endl;

  return 0;
}
