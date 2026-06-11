#include <iostream>
using namespace std;

int main(){
  string a;
  cin >> a;

  for( int i=0; i<a.size(); i++ ){
    if( (i+1)%2==1 ){
      cout << a[i];
    }
  }
  return 0;
}
