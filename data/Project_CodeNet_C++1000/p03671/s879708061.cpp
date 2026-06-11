#include <iostream>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int d[3];
  d[0]=a+b;
  d[1]=a+c;
  d[2]=b+c;
  int min=d[0];
  for(int i=0;i<3;i++){
    if(min>d[i]){
      min=d[i];
    }
  }
  cout<<min;
}