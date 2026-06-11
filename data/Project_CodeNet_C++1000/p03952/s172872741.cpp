#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin>>n>>x;
  if (n == 1) {
    cout<<"Yes"<<endl;
    cout<<1<<endl;
    return 0;
  }
  if (x == 1 || x == 2*n - 1) {
    cout<<"No"<<endl;
    return 0;
  }
  if (n == 2) {
    cout<<"Yes"<<endl;
    cout<<1<<endl;
    cout<<2<<endl;
    cout<<3<<endl;
    return 0;
  }
  int a[2*n-1];
  for (int i=0; i<2*n-1; i++) a[i] = 0;
  set<int> unused;
  for (int i=0; i<2*n-1; i++) unused.insert(i+1);

  a[n-1] = x;
  unused.erase(x);
  a[n-2] = x - 1;
  unused.erase(x-1);
  a[n] = x + 1;
  unused.erase(x+1);
  if (x == 2 * n - 2) {
    a[n+1] = x - 2;
    unused.erase(x-2);
  } else {
    a[n-3] = x + 2;
    unused.erase(x+2);
  }

  int idx = 0;
  for (int i: unused) {
    while (a[idx] != 0) {
      ++idx;
    }
    a[idx] = i;
  }
  cout<<"Yes"<<endl;
  for (int i=0; i<2*n-1; i++) {
    cout<<a[i]<<endl;
  }
}