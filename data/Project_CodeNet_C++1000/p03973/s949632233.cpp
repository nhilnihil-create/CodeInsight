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
#include <deque>
#include <set>
#include <stack>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;

int main(){

  int N; cin >> N;
  vector <ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  ll ans = A[0] - 1, now = 2;
  for (int i = 1; i < N; i++){
    if (A[i] == now){
      now++;
    }else{
      ans += (A[i] - 1) / now;
    }
  }
  cout << ans << endl;

  return 0;
}
