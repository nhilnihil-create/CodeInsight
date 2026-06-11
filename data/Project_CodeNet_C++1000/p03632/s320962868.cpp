#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int a,b,c,d; cin >> a >> b >> c >> d;
  int ans = max(a,c)<min(b,d) ? min(b,d)-max(a,c):0;
  
  cout << ans << endl;
  
  return 0;
}
