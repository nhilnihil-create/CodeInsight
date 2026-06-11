#include <iostream>
using namespace std;

int main(void){
  int n,m,k,ans;
  
  cin >> n >> m >> k;
  ans = 0;
  for (int i=0; i<=n; i++){
    for (int j=0; j<=m; j++){
      int x;
      x = i*m+j*n-2*i*j;
//      cout << i << j << x << endl;
      if (x==k) ans=1;
    }
  }
  cout << (ans?"Yes":"No") << endl;
  return 0;
}
