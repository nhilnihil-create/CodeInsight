#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int x,a,b; cin >> x >> a >> b;

  if(b>a+x) cout << "dangerous" << endl;
  else if(b<=a+x && b>a) cout << "safe" << endl;
  else cout << "delicious" << endl;
  
  return 0;
}
