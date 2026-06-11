#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, x;

//       4
//     3 4 5
//   2 3 4 5 6
// 1 2 3 4 5 6 7


//       2
//     5 2 2
//   5 5 2 2 3 
// 4 5 6 1 2 3 7

//       2
//     4 2 2
//   5 4 2 2 3 
// 5 4 6 1 2 3 7

//       6
//     5 6 6
//   2 5 6 6 4
// 1 2 5 6 7 4 3

// 同じのが真ん中らへんに２つ連続で出たら、絶対それ。

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n >> x;
  int N = n * 2 - 1;
  if(x == 1 || x == N) {
    cout << "No" << '\n';
  } else {
    vector<int> ans(N + 1);
    ans[N / 2] = x;
    ans[N / 2 - 1] = x - 1;
    ans[N / 2 + 1] = x + 1;
    ans[N / 2 + 2] = x - 2;

    queue<int> q;
    for(int i = 1; i <= N; ++i) {
      if(i == x || i == x-1 || i == x+1 || i == x-2) continue;
      q.push(i);
    }
    for(int i = 0; i < N; ++i) {
      if(ans[i] == 0) {
        ans[i] = q.front();
        q.pop();
      }
    }

    cout << "Yes" << '\n';
    for(int i = 0; i < ans.size()-1; ++i) cout << ans[i] << '\n';
  }
  return 0;
}