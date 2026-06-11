#include <iostream>

using namespace std;

const int MAX_N = 2e5 + 5;
const int ALPH = 26;

int arr [MAX_N];
int rmost [ALPH][MAX_N]; // rightmost appearance of i that is <= j
int lmost [ALPH][MAX_N];
int dp [MAX_N][ALPH];

void report (int length, int start) {
  int cur = start, pos = lmost[start][0];
  for (int k = length - 1; k >= 0; k--) {
    cout << (char) ('a' + cur);    
    if (k != 0) {
      for (int i = 0; i < ALPH; i++) {
        if (dp[k][i] <= pos) {
          pos = lmost[i][pos + 1];
          cur = i;
          break;
        }
      }
    }
  }
  cout << endl;
  exit(0);
}

int main () {
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int n = s.size();
  for (int i = 1; i <= n; i++) {
    arr[i] = s[i - 1] - 'a';
  }

  for (int i = 1; i <= n; i++) {
    rmost[arr[i]][i] = i;
    lmost[arr[i]][i] = i;
  }

  for (int i = 0; i < ALPH; i++) {
    lmost[i][n + 1] = n + 1;
    for (int j = n; j >= 0; j--) {
      if (lmost[i][j] == 0) {
        lmost[i][j] = lmost[i][j + 1];
      }
    }
  }

  for (int i = 0; i < ALPH; i++) {
    for (int j = 1; j <= n; j++) {
      if (rmost[i][j] == 0) {
        rmost[i][j] = rmost[i][j - 1];
      }
    }
  }

  for (int i = 0; i < ALPH; i++) {
    dp[1][i] = rmost[i][n];
    if (dp[1][i] == 0) {
      report(1, i);
    }
  }

  for (int k = 2; k <= n; k++) {
    int mn = n;
    for (int i = 0; i < ALPH; i++) {
      mn = min(mn, dp[k - 1][i]);
    }

    for (int i = 0; i < ALPH; i++) {
      dp[k][i] = rmost[i][mn - 1];
      if (dp[k][i] == 0) {
        report(k, i);
      }
    }
  }
}
