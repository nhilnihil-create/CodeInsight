#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int s[N], sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> s[i];
    sum += s[i];
  }
  if (sum%10) {
    cout << sum;
  } else {
  	sort(s,s+N);
    for (int i = 0; i < N; i++) {
      if (s[i]%10) {
        cout << sum-s[i];
        return 0;
      }
    }
    cout << 0;
  }
}