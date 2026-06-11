#include <bits/stdc++.h>
using namespace std;

int main() {
  int s;
  cin >> s;
  vector<int> input(s);
  for (int i = 0; i < s; i++) {
    cin >> input[i];
  }
  sort(input.begin(), input.end());
  int min = input[0];
  int max = input[input.size() - 1];
  int ans = 9000000;

  for (int i = min; i <= max; i++) {
    int total = 0;
    for (int j = 0; j < input.size(); j++) {
      total += (i - input[j]) * (i - input[j]);
    }
    if (ans > total)
      ans = total;
  }

  cout << ans << endl;
}