#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,n;
  cin >> N;
    
    for(int i;i < N;i++) {
      int l,r; cin >> l >> r;
      n += (r-l+1);}
  cout << n << endl;
}
