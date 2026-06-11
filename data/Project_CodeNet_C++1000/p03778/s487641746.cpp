#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int w,a,b; cin >> w >> a >> b;

  int ans;
  if(a+w<b){
    ans = b-(a+w);
    cout << ans << endl;
  }
  else if(b+w<a){
    ans = a-(b+w);
    cout << ans << endl;
  }
  else cout << "0" << endl;
  
  return 0;
}
