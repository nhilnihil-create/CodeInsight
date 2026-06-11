#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
 
  int n, k;
  cin >> n >> k;
  
  int ans = k;
  REP(i,n-1) {
    ans *= (k-1);
  }
  
  cout << ans << endl;
 
}