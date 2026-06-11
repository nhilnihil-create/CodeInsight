#include <iostream>
using namespace std;

int sumation(int a){
  if(a==1){
    return 1;
  }
  else{
    return a + sumation(a-1);
  }
}

int main(){
  int a;
  cin>>a;
  cout<<sumation(a)<<endl;
}