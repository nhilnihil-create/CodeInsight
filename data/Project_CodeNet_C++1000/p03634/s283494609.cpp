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

vector<ll> dist;
map<pair<int, int>, int> mp;
map<int, vector<int>> v;

void solveDist(int now, int before, ll count) {
  rep (i, v[now].size()) {
    if (v[now][i] == before) continue;
    ll newCount = count + mp[make_pair(now, v[now][i])];
    dist[v[now][i]] = newCount;
    solveDist(v[now][i], now, newCount);
  }
}

int main() {
  int n;
  cin >> n;
  rep (i, n - 1) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    v[a].push_back(b);
    v[b].push_back(a);
    mp[make_pair(a, b)] = c;
    mp[make_pair(b, a)] = c;
  }

  int q, k;
  cin >> q >> k;
  k--;

  dist = vector<ll>(n);
  dist[k] = 0;
  solveDist(k, -1, 0);

  rep (i, q) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    P(dist[x] + dist[y]);
  }

  // rep (i, n) {
  //   P(dist[i]);
  // }

  return 0;
}

