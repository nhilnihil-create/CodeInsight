#include <bits/stdc++.h>
using namespace std;

int main(){
  string x;
  cin >> x;
  
  int l = x.size();
  stack<char> ans;
  for(int i = 0; i < l; i++){
    char now = x.at(i);
    if(now == 'S') ans.push(now);
    else if(ans.size() == 0) ans.push(now);
    else if(ans.top() == 'S') ans.pop();
    else ans.push(now);
  }
  
  cout << ans.size() << endl;
}