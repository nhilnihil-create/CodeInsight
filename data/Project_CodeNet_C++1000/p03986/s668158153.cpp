#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
  int i,n;
  string x;
  stack<char> sta;
  cin >> x;
  n = x.size();
  for(i=0;i<n;i++){
    if(sta.empty()) sta.push(x[i]);
    else if(sta.top() == 'S' && x[i]=='T') sta.pop();
    else sta.push(x[i]);
  }
  
  cout << sta.size() << endl;
  return 0;
}