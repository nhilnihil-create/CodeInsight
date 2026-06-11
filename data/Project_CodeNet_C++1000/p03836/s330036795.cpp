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
  int s[2], t[2];
  rep (i, 2) cin >> s[i];
  rep (i, 2) cin >> t[i];

  int yD = t[1] - s[1];
  int xD = t[0] - s[0];

  rep (i, yD) cout << "U";
  rep (i, xD) cout << "R";
  rep (i, yD) cout << "D";
  rep (i, xD + 1) cout << "L";
  rep (i, yD + 1) cout << "U";
  rep (i, xD + 1) cout << "R";
  cout << "DR";
  rep (i, yD + 1) cout << "D";
  rep (i, xD + 1) cout << "L";
  cout << "U" << endl;




  return 0;
}

