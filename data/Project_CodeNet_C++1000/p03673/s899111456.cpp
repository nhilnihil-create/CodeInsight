#include <bits/stdc++.h>
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)

typedef unsigned long long ull;
typedef long long ll;

const int INF = 1001001001;
const ll MOD = 1e9 + 7;

using namespace std;
using P = pair<int,int>;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }

int main() {
  int n; cin >> n;

  vector<ll> a(n); deque<ll> b;
  rep(i, n) {
      cin >> a[i];
      if (i%2 == 1) b.push_front(a[i]);
      else b.push_back(a[i]);
    //   reverse(begin(b), end(b));
    //   rep(j, n) cout << b[j] << " ";
  }

  if (n%2 == 1) reverse(begin(b), end(b));
  rep(i, n) cout << b[i] << " ";
  cout << endl;
  return 0;
}