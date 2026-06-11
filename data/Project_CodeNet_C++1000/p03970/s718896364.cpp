#include <iostream>
using namespace std;
int main(){
  string s;s = "CODEFESTIVAL2016";
  string t;cin>>t;
  int a = 0;
  for(int i = 0; t.size() > i; i++){
    if(s[i]!=t[i])a++;
  }
  cout << a << endl;
}