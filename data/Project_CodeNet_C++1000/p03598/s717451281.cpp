#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,k,x,s=0;
  cin >> n >> k;
  for (int i=0; i<n; i++) {
    cin >> x;
    if (x>k/2) {
      s+=(k-x)*2;
    } else {
      s+=x*2;
    }
  }
  cout << s << endl;
}