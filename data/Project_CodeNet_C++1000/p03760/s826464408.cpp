#include <iostream>
#include <string>
using namespace std;

int main(void){
  string o,e;
  cin>>o>>e;
  
  int length=o.size()<e.size()? o.size():e.size();
  
  for(int i=0;i<length;i++){
    cout<<o[i]<<e[i];
  }
  if(o.size()<e.size())cout<<e[length];
  else if(o.size()>e.size())cout<<o[length];
  
  return 0;
}