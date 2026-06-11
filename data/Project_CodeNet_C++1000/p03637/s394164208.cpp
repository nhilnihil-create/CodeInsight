#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll N; cin >> N;
  ll a[N];
  ll no, n4;
  no = 0; n4 = 0;
  for (ll i = 0; i < N; i++) {
    cin >> a[i];
    if (a[i]%2==1) {no++;}
    if (a[i]%4==0) {n4++;}
  }
  if (no > n4+1) {cout << "No" << endl; return 0;}
  if (no == n4+1 && 2*no-1 < N) {cout << "No" << endl; return 0;}
  cout << "Yes" << endl;
}