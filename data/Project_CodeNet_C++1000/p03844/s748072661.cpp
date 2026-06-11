#include <iostream>
using namespace std;
int main(){
 long long int a,b,res;
  char c;
  cin>>a>>c>>b;

  if(c == '+'){
    res = a + b;
    cout<<res<<endl;
  }
  else{
    res = a-b;
    cout<<res<<endl;
  }
}