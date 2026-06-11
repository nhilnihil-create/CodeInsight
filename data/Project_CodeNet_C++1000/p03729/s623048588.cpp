#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string a,b,c; cin >> a >> b >> c;
  bool ok = true;
  if(a[a.size()-1] != b[0]) ok = false;
  if(b[b.size()-1] != c[0]) ok = false;

  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
  
  return 0;
}
