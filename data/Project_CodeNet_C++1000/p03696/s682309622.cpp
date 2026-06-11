#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
  int i,n,a=0,b=0;
  string s;
  stack<char> sta;
  cin >> n;
  cin >> s;
  for(i=0;i<n;i++){
    if(!sta.empty() && s[i]==')' && sta.top()=='('){
      sta.pop();
      b--;
    }else{
      sta.push(s[i]);
      if(s[i]==')') a++;
      else b++;
    }
  }
  for(i=0;i<a;i++) cout << "(";
  cout << s;
  for(i=0;i<b;i++) cout << ")";
  cout << "\n";
  return 0;
}