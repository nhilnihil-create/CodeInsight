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
#define mp make_pair
 
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

int N; string S;
ll ans = 0;

int Solve(ll sum, ll now, int turn){
  if (turn == N){
    ans += sum + now;
    return 0;
  }
  Solve(sum + now, 0, turn + 1);
  now *= 10; now += S[turn] - '0';
  Solve(sum, now, turn + 1);
  return 0;
}

int main(){
  cin >> S; N = S.length();
  Solve(0, 0, 0);
  cout << ans << endl;

  return 0;
}
