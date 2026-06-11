#include <bits/stdc++.h>
using namespace std;

string join(const vector<int> &arr) {
  string result = "";
  result += to_string(arr[0]);
  for (int i = 1; i < arr.size(); i++) {
    result += (" " + to_string(arr[i]));
  }
  return result;
}

int main(void) {
  int n;
  cin >> n;
  vector<int> as(n);
  for (int i = 0; i < n; i++) {
    int idx = n / 2 + ((n + i) % 2 == 1 ? -1 : 1) * ((i + 1) / 2);
    cin >> as[idx];
  }

  cout << join(as) << endl;
  return 0;
}