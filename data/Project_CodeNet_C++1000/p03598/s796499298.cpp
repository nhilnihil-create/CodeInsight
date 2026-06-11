#include <iostream>
using namespace std;

int main() {
  int N,K,x,a=0;
  cin >> N >> K;
  while(N--){
    cin >> x;
    if(x < (K-x))
      a += x*2;
    else
      a += (K-x)*2;
  }
  cout << a << endl;
}
