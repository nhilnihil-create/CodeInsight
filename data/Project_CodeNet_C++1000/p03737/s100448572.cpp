#include<iostream>
using namespace std;
int main(){
  string a,b,c;
  cin>>a>>b>>c;
  char dif='A'-'a';
  printf("%c%c%c",a[0]+dif,b[0]+dif,c[0]+dif);
  return 0;
}