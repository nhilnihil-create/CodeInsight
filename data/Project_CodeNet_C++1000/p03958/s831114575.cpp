#include <bits/stdc++.h>
using namespace std;

int main() {
  int K,T; cin >> K >> T;
  vector<long long> a(T);
  long long mx = 0;
  for(int i = 0; i < T; i ++)cin >> a[i],mx = max(a[i],mx);
  cout << max(mx - 1 - (K - mx), 0LL) << endl;

}