#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define fsp(x) cout << fixed << setprecision(x)
const ll inf = LLONG_MAX;
const long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

vll dijkstra(ll n, vector<vector<vll>> nx, ll start) {
  vll dist(n, inf);
  dist[start] = 0;

  priority_queue<vll, vector<vll>, greater<vll>> pq;
  for (ll i = 0; i < nx[start].size(); i++) {
    pq.push(nx[start][i]);
  }

  for (ll i = 0; i < n - 1; i++) {
    vll w = pq.top();
    pq.pop();
    dist[w[1]] = w[0];
    for (ll j = 0; j < nx[w[1]].size(); j++) {
      if (dist[nx[w[1]][j][1]] == inf) {
        pq.push({dist[w[1]] + nx[w[1]][j][0], nx[w[1]][j][1]});
      }
    }
  }
  return dist;
}

int main() {
  ll n;
  cin >> n;
  vector<vector<vll>> nx(n, vector<vll>(0));
  for (ll i = 0; i < n - 1; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    nx[a - 1].push_back({c, b - 1});
    nx[b - 1].push_back({c, a - 1});
  }
  ll q, k;
  cin >> q >> k;
  vll dist = dijkstra(n, nx, k - 1);
  for (ll i = 0; i < q; i++) {
    ll x, y;
    cin >> x >> y;
    cout << dist[x - 1] + dist[y - 1] << endl;
  }
}