#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<vector<ll>> Matrix;

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
  //vector<ll> total(n+1, 0);
  rep(i, n) {
    cin >> a[i];
    //total[i+1] = total[i] + a[i];
  }
  //vector<ll> hoge = total;
  ll sum = 0;
  ll ans = 0;
  rep(i, n) {
    sum += a[i];
    if (i % 2 == 0 && sum <= 0) {
      sum -= a[i];
      ll tmp = 1-sum;
      ans += abs(tmp-a[i]);
      //cout << i << ": " << a[i] << ", " << tmp << ", " << ans << endl;
      sum += tmp;
    } else if (i % 2 == 1 && sum >= 0) {
      sum -= a[i];
      ll tmp = -1-sum;
      ans += abs(tmp-a[i]);
      //cout << i << ": " << a[i] << ", " << tmp << ", " << ans << endl;
      sum += tmp;
    }
  }
  ll ans2 = 0;
  sum = 0;
  rep(i, n) {
    sum += a[i];
    if (i % 2 == 0 && sum >= 0) {
      sum -= a[i];
      ll tmp = -1-sum;
      ans2 += abs(tmp-a[i]);
      sum += tmp;
    } else if (i % 2 == 1 && sum <= 0) {
      sum -= a[i];
      ll tmp = 1-sum;
      ans2 += abs(tmp-a[i]);
      sum += tmp;
    }
  }
  cout << min(ans, ans2) << endl;
  return 0;
}
