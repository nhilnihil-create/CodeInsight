#include <iostream>
using namespace std;
int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  if(a<=c){
    if(c<b){
      if(b<d) cout << b-c << "\n";
      else cout << d-c << "\n";
    }
    else cout << 0 << "\n";
  }
  else {
    if(a<d){
      if(d<b) cout << d-a << "\n";
      else cout << b-a << "\n";
    }
    else cout << 0 << "\n";
  }
  return 0;
}