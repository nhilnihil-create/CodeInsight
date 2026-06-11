#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> ab(n);
  vector<pair<int, int>> cd(m);
  vector<pair<int, int>> dist(n);
  rep(i, n) cin >> ab[i].first >> ab[i].second;
  rep(i, m) cin >> cd[i].first >> cd[i].second;
  rep(i, n) {
    int min_dist = 1e9;
    rep(j, m) {
      if((abs(ab[i].first - cd[j].first)
         +abs(ab[i].second - cd[j].second)) < min_dist) {
        min_dist = abs(ab[i].first - cd[j].first)
                    + abs(ab[i].second - cd[j].second);
        dist[i].first = min_dist;
        dist[i].second = j;
      }
    }
  }
  rep(i, n) {
    cout << dist[i].second + 1 << endl;
  }
  return 0;
}
  