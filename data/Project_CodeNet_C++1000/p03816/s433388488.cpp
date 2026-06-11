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

int N, Count[100005];
int main(){
  cin >> N;
  for (int i = 0; i < N; i++){
    int A; cin >> A; Count[A]++;
  }
  
  int cnt = 0;
  for (int i = 0; i < 100005; i++){
    if (Count[i]) cnt += Count[i] - 1;
  }
  if (cnt % 2 != 0) cnt++;
  cout << N - cnt << endl;

  return 0;
}
