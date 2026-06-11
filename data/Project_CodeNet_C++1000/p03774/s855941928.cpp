#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<string> vs;
const ll mod = 1e9+7;
const ll inf = 1e17;
const int INF = 1e9;
const double PI = acos(-1);
#define fo(i, a, b) for(int i = a; i < b; i++)
#define re(i, n) fo(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(s) s.begin(), s.end()
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
int main()
{
  int n, m;
  cin >> n >> m;
  vl a(n), b(n), c(m), d(m);
  re(i, n) cin >> a[i] >> b[i];
  re(j, m) cin >> c[j] >> d[j];

  re(i, n) {
    ll min = inf;
    int k = 0;
    re(j, m) {
      ll s = llabs(a[i] - c[j]) + llabs(b[i] - d[j]);
      if(s < min) {
        min = s;
        k = j + 1;
      }
    }
    cout << k << endl;
  }

  return 0;
}
