#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int x, t;
  cin >> x >> t;
  int ans = x - t;
  if(ans<0) ans = 0;
  cout << ans << endl;
  return 0;
}
