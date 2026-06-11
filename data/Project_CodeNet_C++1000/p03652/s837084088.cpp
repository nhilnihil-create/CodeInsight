#include <climits>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(N, vector<int>(M));
  rep(i, N) {
    rep(j, M) {
      cin >> A[i][j];
      A[i][j]--;
    }
  }

  int answer = INT_MAX;
  vector<bool> hold(M, true);
  rep(k, M) {
    vector<int> like(M, 0);
    rep(i, N) {
      rep(j, M) {
        if (hold[A[i][j]]) {
          like[A[i][j]]++;
          break;
        }
      }
    }

    int max_like = -1;
    int max_sports = 0;
    rep(j, M) {
      if (max_like < like[j]) {
        max_like = like[j];
        max_sports = j;
      }
    }
    answer = min(answer, max_like);
    hold[max_sports] = false;
    if (answer == 1) break;
  }
  cout << answer << endl;
  return 0;
}
