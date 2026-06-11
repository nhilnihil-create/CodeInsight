#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  vector<int> odd, even;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) odd.push_back(a[i]);
    else even.push_back(a[i]);
  }
  if (n % 2 == 0) {
    reverse(even.begin(), even.end());
    for (int i = 0; i < even.size(); i++) {
      cout << even[i] << " ";
    }
    for (int i = 0; i < odd.size(); i++) {
      cout << odd[i] << " ";
    }
    cout << endl;
  } else {
    reverse(odd.begin(), odd.end());
    for (int i = 0; i < odd.size(); i++) {
      cout << odd[i] << " ";
    }
    for (int i = 0; i < even.size(); i++) {
      cout << even[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
