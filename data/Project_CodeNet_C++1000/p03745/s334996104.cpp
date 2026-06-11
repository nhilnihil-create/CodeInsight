#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const char wall = '#';
vector<vector<char>> fields;
vector<vector<bool>> used;
vector<vector<ll>> dist;
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};

vector<ll> A;
// vectorのリサイズ
// A.resize(N);

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a*b/gcd(a, b);}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  char f = ' ';
  ll ans = 1;
  rep(i, n) {
    if(i == 0) continue;
    if (a[i] > a[i-1]) {
      if (f == '-') {
        ans++;
        f = ' ';
        continue;
      }
      f = '+';
    }
    if (a[i] < a[i-1]) {
      if (f == '+') {
        ans++;
        f = ' ';
        continue;
      }
      f = '-';
    }
  }
  cout << ans << endl;
  return 0;
}
