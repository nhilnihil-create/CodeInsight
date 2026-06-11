#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  int kari1 = 0;
  int kari4 = 0;
  for (int i = 0; i < N; i++) cin >> a[i];
  for (int i = 0; i < N; i++) {
    if (a[i] % 2 == 1) kari1++;
    else if (a[i] % 4 == 0) kari4++;
  }
  if (kari1 > (kari4+1)) cout << "No" << endl;
  else if (kari1 > kari4 && (kari1+kari4)<N) cout << "No" << endl;
  else cout << "Yes" << endl;
}
