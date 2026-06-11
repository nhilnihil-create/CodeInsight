#include <iostream>
using namespace std;

int main(){
  int i, n, atta = 0;
  cin >> n;
  int a[n];
  for( i = 0; i < n; i++ ){
    cin >> a[i];
    if( a[i]%2==1 ){
      atta++;
    }
  }
  if( atta%2==1 ){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
  }
  return 0;
}
  