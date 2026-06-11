#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>
using namespace std;
typedef long long int ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl

const int INF = 1001001001;
const int mod = 1000000007;
#define PI 3.14159265359;

void P(int x) {cout << x << endl;}
void P(long x) {cout << x << endl;}
void P(double x) {cout << x << endl;}
void P(ll x) {cout << x << endl;}
void P(string x) {cout << x << endl;}
void P(char x) {cout << x << endl;}

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}


int main() {
  int n, t;
  cin >> n >> t;
  long ans = 0;
  long last = 0;
  rep (i, n) {
    int tmp;
    cin >> tmp;
    ans += t;
    if (last > tmp) ans -= (last - tmp);
    last = t + tmp;
    // P(ans);
  }
  P(ans);
  return 0;
}