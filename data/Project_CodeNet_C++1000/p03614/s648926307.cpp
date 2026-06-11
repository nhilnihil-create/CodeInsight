#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli>> mat;

lli n;
vll p;
lli ans;

int main(){
  cin >> n;
  p = vll(n+1);
  for(lli i = 1;i <= n;i++) cin >> p[i];
  for(lli i = 1;i <= n;i++){
    if(p[i] == i) swap(p[i],p[i == n ? i-1 : i+1]),ans++;
  }
  cout << ans << endl;
  return 0;
}
