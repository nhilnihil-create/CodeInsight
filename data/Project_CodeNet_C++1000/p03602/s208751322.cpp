#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 305;

int arr [MAX_N][MAX_N];
int del [MAX_N][MAX_N];

int main () {
  int n;
  cin >> n;

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
      ans += arr[i][j];
    }
  }

  for (int u = 0; u < n; u++) {
    for (int v = 0; v < n; v++) {
      for (int w = 0; w < n; w++) {
        if (arr[u][v] + arr[v][w] < arr[u][w]) {
          cout << -1 << endl;
          return 0; 
        } else if (arr[u][v] + arr[v][w] == arr[u][w]) {
          if (u != v && v != w && !del[u][w]) {
            del[u][w] = 1;
            ans -= arr[u][w];
          }
        }
      }
    }
  }

  ans /= 2;
  cout << ans << '\n';
}
