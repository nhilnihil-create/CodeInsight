#include <iostream>
using namespace std;

int main(){
  int a,b;
  cin>>a>>b;
  if (a == 0){
    cout<< "Zero"<<endl;
    return 0;
  }
  if (b == 0){
    cout<< "Zero"<<endl;
    return 0;
  }
  if (a>0 ){
    cout<< "Positive"<<endl;
    return 0;
  }
  if (b<0){
    int x = b - a +1;
    if (x%2 == 0){
      cout<< "Positive"<<endl; 
      return 0;
    }
    else{
      cout<< "Negative"<<endl;
      return 0;
    }
  }
  else{
    cout<< "Zero"<<endl;
    return 0;
  }  
}