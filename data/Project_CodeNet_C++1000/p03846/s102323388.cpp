#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <stdio.h>
#include <unistd.h>
using namespace std;
typedef long long int ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define drep(i, n) for(int i = n - 1; i >= 0; i--)
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define yes cout << "yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define no cout << "no" << endl
#define PI 3.14159265359

const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const int mod = 1000000007;

void P(int x) {cout << x << endl;}
void P(long x) {cout << x << endl;}
void P(double x) {cout << x << endl;}
void P(ll x) {cout << x << endl;}
void P(string x) {cout << x << endl;}
void P(char x) {cout << x << endl;}

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}


int main() {
  int n;
  cin >> n;

  vector<int> v((n + 1) / 2);
  int flag = 0;
  rep (i, n) {
    int a;
    cin >> a;
    a /= 2;
    if (a >= (n + 1) / 2) {
      flag = 1;
    }
    v[a]++;
    if (v[a] > 2) flag = 1;
  }
  if (n % 2 != 0 && v[0] != 1) {
    flag = 1;
  }
  if (flag == 1) {
    P(0);
  } else {
    int count = 0;
    rep (i, v.size()) {
      if (v[i] == 2) count++;
    }
    ll ans = 1;
    rep (i, count) {
      ans = (ans * 2) % mod;
    }
    P(ans);
  }

  return 0;
}

