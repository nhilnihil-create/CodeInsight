#include <iostream>

using namespace std;

typedef long long llong;
const llong MOD=1000000007;

int main(){
  llong n,m; cin >> n >> m;
  llong sumx=0,sumy=0;
  for(llong i=1;i<=n;i++){
    llong x; cin >> x;
    sumx=(sumx+(2*i-n-1)*x)%MOD;
  }
  for(llong i=1;i<=m;i++){
    llong y; cin >> y;
    sumy=(sumy+(2*i-m-1)*y)%MOD;
  }
  cout << (sumx*sumy)%MOD << endl;
}