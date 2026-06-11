#include <iostream>
#include <string>
using namespace std;

int main(void){
  string a,b,c;
  cin>>a>>b>>c;
  
  a[0]=toupper(a[0]);
  b[0]=toupper(b[0]);
  c[0]=toupper(c[0]);
  
  cout<<a[0]<<b[0]<<c[0]<<endl;
  return 0;
  
}