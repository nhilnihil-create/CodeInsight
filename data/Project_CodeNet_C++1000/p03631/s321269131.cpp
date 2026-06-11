#include<iostream>
using namespace std;
int main(){
  int a;
  cin>>a;
  int b[3];
  for(int i=0;i<3;i++){
    b[i]=a%10;
    a=a/10;
  }
  printf("%s",b[0]==b[2]?"Yes":"No");
  return 0;
}