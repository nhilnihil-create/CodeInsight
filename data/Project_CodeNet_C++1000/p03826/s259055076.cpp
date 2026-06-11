#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int a,b; cin >> a >> b;
  int c,d; cin >> c >> d;

  int ans = a*b>=c*d ? a*b:c*d;

  cout << ans << endl;
  
  return 0;
}
