#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int n;
  cin >> n;
  
  int t[n], s = 0;
  REP(i,n) {
    cin >> t[i];
    s += t[i];
  }
  
  int m;
  cin >> m;
  
  int p, x;
  REP(j,m) {
    cin >> p >> x;
    cout << s - t[p-1] + x << endl;
  }

}
