#include <iostream>
#include <string>

using namespace std;

const int MAX_N = 1e5 + 5;

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  string s;
  int K;
  cin >> s >> K;

  int n = s.size();
  for (int i = 0; i < n; i++) {
    arr[i] = s[i] - 'a';
  }

  for (int i = 0; i < n; i++) {
    if (arr[i] != 0 && K >= 26 - arr[i]) {
      K -= 26 - arr[i];
      arr[i] = 0;
    }
  }

  arr[n - 1] += K;
  arr[n - 1] %= 26;

  for (int i = 0; i < n; i++) {
    cout << (char) ('a' + arr[i]);
  }
  cout << endl;
}
