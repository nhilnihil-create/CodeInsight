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
  int W, H; cin >> W >> H;

  vector < pair<ll, bool> > PQ;
  for (int i = 0; i < W; i++){
    ll P; cin >> P;
    PQ.push_back(make_pair(P, true));
  }
  for (int i = 0; i < H; i++){
    ll Q; cin >> Q;
    PQ.push_back(make_pair(Q, false));
  }
  sort(PQ.begin(), PQ.end());
  
  ll ans = 0;
  ll T = H + 1, F = W + 1;
  for (int i = 0; i < PQ.size(); i++){
    if (PQ[i].second == true){
      ans += PQ[i].first * T;
      F--;
    }else{
      ans += PQ[i].first * F;
      T--;
    }
  }
  cout << ans << endl;
  return 0;
}
