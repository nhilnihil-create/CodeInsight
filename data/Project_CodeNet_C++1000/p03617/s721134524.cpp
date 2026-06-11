#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long

using namespace std;
using P = pair<int,int>;

int main(){

  int Q, H, S, D, Q8, H4, S2, Q4, H2;
  ll N;
  cin >> Q >> H >> S >> D >> N;

  Q8 = Q * 8;
  Q4 = Q * 4;
  H4 = H * 4;
  H2 = H * 2;
  S2 = S * 2;

  ll divN = N / 2;
  ll modN = N % 2;

  // cout << min(Q8, min(H4, min(S2, D))) << endl;
  // cout << min(Q4, min(H2, S)) << endl;

  ll ans = divN * min(Q8, min(H4, min(S2, D))) + modN * min(Q4, min(H2, S));

  cout << ans << endl;

  return 0;
}