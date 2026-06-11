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

int main(){
  int SX, SY, TX, TY;
  cin >> SX >> SY >> TX >> TY;

  for (int i = 0; i < TX - SX; i++) printf("R");
  for (int i = 0; i < TY - SY; i++) printf("U");
  for (int i = 0; i < TX - SX; i++) printf("L");
  for (int i = 0; i < TY - SY; i++) printf("D");

  printf("D");
  for (int i = 0; i < TX - SX + 1; i++) printf("R");
  for (int i = 0; i < TY - SY + 1; i++) printf("U");  
  printf("LU");
  for (int i = 0; i < TX - SX + 1; i++) printf("L");
  for (int i = 0; i < TY - SY + 1; i++) printf("D");
  printf("R");

  cout << endl;


  return 0;
}
