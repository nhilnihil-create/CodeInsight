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

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

ll I, O, T, J, L, S, Z;
int main(){
  cin >>I>>O>>T>>J>>L>>S>>Z;

  ll ans = O;
  ans += (I/2+ L/2+ J/2) * 2;

  ll ans2 = O;
  if (I > 0 && J > 0 && L > 0){
    ans2 += 3;
    ans2 += ((I-1)/2 + (L-1)/2+(J-1)/2) * 2;
  }
  cout << max(ans, ans2) << endl;

  return 0;
}
