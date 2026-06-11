#include <bits/stdc++.h>
using namespace std;
vector<int> likes(10, 1);
bool isok(int i, vector<int> &likes) {
  while (i) {
    int a = i % 10;
    if (!likes[a]) return false;
    i /= 10;
  }
  return true;
}

int main() {
  int k;
  int n;
  cin >> n >> k;
  vector<int> likes(10, 1);
  for (int i = 0; i < k; i++) {
    int t;
    cin >> t;

    likes[t] = 0;
  }
  // cout << likes[9] << endl;
  // sort(likes.begin(), likes.end());
  int answer = n;
  while (true) {
    if (isok(answer, likes)) {
      cout << answer << endl;
      break;
    }

    else
      answer++;
  }
}
