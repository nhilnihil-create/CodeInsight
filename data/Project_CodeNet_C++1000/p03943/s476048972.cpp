#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  vector<int> a(3);
  rep(i, 3) cin >> a[i];
  sort(a.rbegin(), a.rend());
  if(a[0] == a[1] + a[2]) cout << "Yes" << endl;
  else cout << "No" << endl;
}