#include <iostream>
using namespace std;

int main(){
  string s;
  int i;
  cin>>s;
  string t;
  
  for(i=0;i<s.size();i=2+i){
    t=t+s[i];
  }
  cout<<t<<endl;
}
