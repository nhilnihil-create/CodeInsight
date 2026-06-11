#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int k,s; cin >> k >> s;

  int ans = 0;
  for(int x = 0;x<=k;++x)
    for(int y = 0;y<=k;++y)
      if(s-(x+y)>=0 && s-(x+y)<=k) ans++;

  cout << ans << endl;
  
  return 0;
}
