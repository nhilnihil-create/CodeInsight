#include <iostream>
 
using namespace std;
 
int main() {
  int A,B;
  cin >> A>> B;
  if(A%3==0&&A!=0){
    cout <<"Possible"<<endl;
    return 0;
  }
  if(B%3==0&&B!=0){
    cout <<"Possible"<<endl;
    return 0;
  }
  if((A+B)%3==0&&(A+B)!=0){
    cout <<"Possible"<<endl;
    return 0;
  }
  if(A%3!=0&&B%3!=0&&(A+B)%3!=0){
    cout <<"Impossible"<<endl;
  }
  if(A==0&&B==0){
    cout <<"Impossible"<<endl;
  }
}
