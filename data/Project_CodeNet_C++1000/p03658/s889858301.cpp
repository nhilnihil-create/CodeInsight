#include <bits/stdc++.h>
using namespace std;
int n,k;
int l[55];
int main() {
  int sum;
  cin >> n >> k;
  for(int i(0); i < n; i++)cin >> l[i];
  sort(l, l+n, greater<int>());
  for(int i(0); i < k; i++){
    sum += l[i];
  }
  cout << sum;
}