#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  stack<char> p;
  p.push('T');
  for(int i=0;i<S.size();i++){
    if(S[i]=='S') p.push('S');
    else if(S[i]=='T'&&p.top()=='S') p.pop();
    else p.push('T');
  }
  cout<<p.size()-1<<endl;
}
    