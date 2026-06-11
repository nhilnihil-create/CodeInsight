#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  string o, e;
  cin >> o >> e;
  
  int a = o.size(), b = e.size();
  
  REP(i,a-1) cout << o[i] << e[i];
  
  if (a == b) cout << o[a-1] << e[b-1];
  else cout << o[a-1];

}
