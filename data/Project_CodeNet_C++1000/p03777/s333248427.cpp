#include <iostream>
#include <string>
 
using namespace std;
 
int main(){
  string a,b;
  cin>>a>>b;
  
  if(a=="H"){
    cout<<b<<endl;
    return 0;
  }else{
    if(b=="H"){
      cout<<"D"<<endl;
    }else {
      cout<<"H"<<endl;
    }
  }
  return 0;
}