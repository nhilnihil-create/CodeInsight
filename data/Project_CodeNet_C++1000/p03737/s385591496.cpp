#include <bits/stdc++.h>
#define rep(i,a,n) for (int i =a; i<n; i++)
using namespace std;

int main() {
  string a[3]; rep(i,0,3) cin >> a[i];
  char A[3]; rep(i,0,3) A[i] = a[i][0] + 'A' - 'a';
  rep(i,0,3) cout << A[i];
  cout << endl;
}