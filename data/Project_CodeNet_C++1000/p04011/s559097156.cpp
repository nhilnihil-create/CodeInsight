#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k,x,y,c=0;
  cin >> n >> k >> x >> y;
  if(n <= k){
    cout << n * x;
    return 0 ;
  }
  c = k * x + (n - k) * y;
  cout << c;
}
