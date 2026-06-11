#include <iostream>
#include <string>
using namespace std;

int main(){
  int n;
  cin>>n;
  string s=to_string(n);
  if(s[0]==s[2]) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}