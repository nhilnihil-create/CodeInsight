#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 
  
  int n, m;
  cin >> n >> m;

  char A[n][n];
  char B[m][m];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cin >> A[i][j];
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) cin >> B[i][j];
  }

  for (int i = 0; i < n - m + 1; ++i) {
    for (int j = 0; j < n - m + 1; ++j) {
      bool is_found = true;

      for (int x = 0; x < m && is_found; ++x) {
        for (int y = 0; y < m && is_found; ++y) {
          if (A[i + x][j + y] != B[x][y]) {
            is_found = false;
          }
        }
      }

      if (is_found) {
        cout << "Yes" << "\n";
        return 0;
      }
    }
  }

  cout << "No" << "\n";
}
