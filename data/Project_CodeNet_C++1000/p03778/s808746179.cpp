#include <iostream>

using namespace std;

int main(){
  int a,b,w;
  cin>>w>>a>>b;
  if((a<=b && b<=a+w) || (b<=a && a<=b+w)){
    cout<<0<<endl;
  }else{
    cout<<min(abs(b-(a+w)),abs((b+w)-a))<<endl;
  }
  return 0;
}