#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, A, B;
  cin >> N >> A >> B;
  string S;
  cin >> S;

  int counter = 0;
  int counter_b = 0;
  vector<bool> result(N, false);
  int limit = A + B;
  int i = 0;
  for (auto c : S) {
    if (counter >= limit) {
      break;
    }
    if (c == 'a') {
      result.at(i) = true;
      ++counter;
    } else if (c == 'b' && counter_b < B) {
      result.at(i) = true;
      ++counter;
      ++counter_b;
    } else {
      ++i;
      continue;
    }
    ++i;
  }

  for (auto b : result) {
    if (b) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
