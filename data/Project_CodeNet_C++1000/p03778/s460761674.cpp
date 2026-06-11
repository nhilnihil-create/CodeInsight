#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define INF INT_MAX;
typedef long long ll;
using namespace std;

int main(){
  int w,a,b;
  cin >> w >> a >> b;
  int x,y,ans;
  x = min(a,b); y = max(a,b);
  if(x+w>y) ans = 0;
  else ans = y-x-w;
  cout << ans << endl;
}