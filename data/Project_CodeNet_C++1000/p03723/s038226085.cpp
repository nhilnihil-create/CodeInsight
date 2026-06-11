#include<iostream>
using namespace std;
int main(){

  int A,B,C;
  cin>>A>>B>>C;
  int Agive,Bgive,Cgive;
  bool flag=0;
  int count=0;
  if(A%2==1||B%2==1||C%2==1){
  
    cout<<count;
    return 0;
  }
  if(A==B&&B==C){
  
    cout<<-1;
    return 0;
  }
  while(flag==0){
  
    Agive=A;
    Bgive=B;
    Cgive=C;
    A=(Bgive+Cgive)/2;
    B=(Agive+Cgive)/2;
    C=(Agive+Bgive)/2;
    if(A%2==1||B%2==1||C%2==1){
  
      flag=1;
    }
    count++;
  }
  cout<<count;
  return 0;
}