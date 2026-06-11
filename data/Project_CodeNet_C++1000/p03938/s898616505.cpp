#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int p[n];
  for (int i=0; i<n; i++) cin>>p[i];

  int c[n];
  int v = n + 1;
  for (int i=0; i<n; i++) {
    c[p[i]-1] = v;
    ++v;
  }
  int a[n], b[n];
  a[0] = 1;
  b[0] = c[0] - 1;
  for (int i=1; i<n; i++) {
    if (c[i] > c[i-1]) {
      b[i] = b[i-1] - 1;
      a[i] = c[i] - b[i];
    } else {
      a[i] = a[i-1] + 1;
      b[i] = c[i] - a[i];
    }
  }
  for (int i=0; i<n; i++) {
    cout<<a[i];
    if (i != n - 1) {
      cout<<" ";
    }
  }
  cout<<endl;
  int d = 0;
  if (b[n-1] <= 0) {
    d = -b[n-1] + 1;
  }
  for (int i=0; i<n; i++) {
    cout<<b[i] + d;
    if (i != n - 1) {
      cout<<" ";
    }
  }
  cout<<endl;
}