#include <iostream>
#include <string>
using namespace std;

int main(){
  string s;
  cin>>s;
  
  int A;//最初にAが出てきた時の番号
  int Z;//最後にZが出てきた時の番号
  
  A=s.find_first_of('A');
  Z=s.find_last_of('Z');
  
  cout<<Z-A+1<<endl;
  return 0;
}