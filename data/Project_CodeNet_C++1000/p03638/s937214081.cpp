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
  int h, w, n;
  cin >> h >> w >> n;
  vector<int> v(n);
  rep (i, n) {
    cin >> v[i];
  }
  int ans[h][w];
  int color = 0;
  int count = 0;
  rep (i, h) {
    if (i % 2 == 0) {
      rep (j, w) {
        if (count >= v[color]) {
          color++;
          count = 0;
        }
        ans[i][j] = color + 1;
        count++;
      }
    } else {
      for (int j = w - 1; j >= 0; j--) {
        if (count >= v[color]) {
          color++;
          count = 0;
        }
        ans[i][j] = color + 1;
        count++;
      }
    }
  }

  rep (i, h) {
    rep (j, w) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}

