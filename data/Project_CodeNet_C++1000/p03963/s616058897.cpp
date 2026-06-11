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

  int N, K;
  cin >> N >> K;
  ll ans = 1;

  for (int i = 0; i < N; i++) {
    if(i == 0) ans = ans*K;
    else ans = ans*(K-1);
  }

  cout << ans << endl;

  return 0;
}