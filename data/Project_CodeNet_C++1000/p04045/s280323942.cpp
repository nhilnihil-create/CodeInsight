#include <iostream>
using namespace std;

int main(){
  int i, tmp, n, nn, k, atta = 0;
  cin >> n >> k;
  int d[10];

  for( i=0; i<10; i++ ){
    d[i] = 0;
  }
  for( i=0; i<k; i++ ){
    cin >> tmp;
    d[tmp] = 1;
  }

  int ok;
  while( atta == 0 ){
    nn = n;
    ok = 1;
    while( nn>0 ){
      if( d[nn%10]==1 ){
        ok = 0;
      }
      nn /= 10;
    }
    if( ok==1 ){
      atta=1;
    }
//    cout << n << " " << endl;
    n++;
  }
  cout << n-1;
  return 0;
}
