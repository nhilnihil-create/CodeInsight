#include <iostream>
using namespace std;
int main(){
  long long kekka = 0;
  int I,O,T,J,L,S,Z;cin>>I>>O>>T>>J>>L>>S>>Z;//IOJL;
  //できる形
  kekka += O;//O=1;

  if(I > 0 && J > 0 && L > 0){
    long long a1 = J/2*2;
    long long a2 = L/2*2;
    long long a3 = I/2*2;
    //cout << a1 << " " << a2 << " " << a3 << endl;
    long long b1 = (J-1)/2*2;
    long long b2 = (L-1)/2*2;
    long long b3 = (I-1)/2*2;
    //cout << b1 << " " << b2 << " " << b3 << endl;
    kekka += max(a1+a2+a3,b1+b2+b3+3);
  }
  else {
    kekka += (J)/2*2;//J=2;
    kekka += (L)/2*2;//L=2;
    kekka += (I)/2*2;//I=2;
  }
  cout << kekka << endl;
}