//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;


int main(){
  ll N, A, B, C, D; cin >> N >> A >> B >> C >> D;

  ll S = B - A;

  ll c = min(C, D), d = max(C, D);

  N--;
  for (ll i = 0; i <= N; i++){
    if (i * C + (i - N) * D <= S && S <= (i - N) * C + i * D){
      cout << "YES" << endl;
      return 0;
    }
  }
  
  
  cout << "NO" << endl;

  return 0;
}
