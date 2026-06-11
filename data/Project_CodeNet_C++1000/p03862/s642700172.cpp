#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int N; long x; cin >> N >> x;
  long a[N]; for (int i =0; i<N; i++) cin >> a[i];
  long ans =0;
  if (a[0] > x) {
    ans = a[0] - x; 
    a[0] = x; 
  }
  for (int i =1; i<N; i++) {
    if (a[i] + a[i-1] > x) {
      ans += a[i] + a[i-1] - x;
      a[i] = x - a[i-1];
    }
  }
  
  cout << ans << endl;
}