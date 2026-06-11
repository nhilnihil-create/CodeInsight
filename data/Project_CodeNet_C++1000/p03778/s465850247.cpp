#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int w,a,b;
  cin >> w >> a >> b;
  int x = min(a,b);
  int y = max(a,b);
  cout << max(0,y-x-w) << endl;
  return 0;
}
