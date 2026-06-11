#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> a(N + 1);

  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }

  int k = 0;
  for (int i = 1; i <= N; i++) {
    if (i == a[a[i]]) k++;
  }
  k /= 2;
  cout << k << endl;
}
