#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  vector<bool> selected(m + 1, true);
  auto getLargestSportAndSize = [&]() {
    vector<int> sportSize(m + 1);
    int largestSport = -1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int sport = a[i][j];
        if (selected[sport]) {
          ++sportSize[sport];
          if (largestSport == -1 || sportSize[sport] > sportSize[largestSport]) {
            largestSport = sport;
          }
          break;
        }
      }
    }
    return make_pair(largestSport, sportSize[largestSport]);
  };
  auto largestSportAndSize = getLargestSportAndSize();
  int ans = largestSportAndSize.second;
  for (int i = 0; i < m - 1; ++i) {
    selected[largestSportAndSize.first] = false;
    largestSportAndSize = getLargestSportAndSize();
    ans = min(ans, largestSportAndSize.second);
  }
  cout << ans << endl;
  return 0;
}
