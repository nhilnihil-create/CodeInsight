#include <bits/stdc++.h>
using namespace std;


int main() {

string S;
cin>>S;
stack<char> s;
int N=S.size();
s.push(S[0]);
for(int i=1;i<N;i++){
  if(!s.empty()&&s.top()=='S'&&S[i]=='T') s.pop();
  else s.push(S[i]);
}
cout<<s.size()<<endl;

}
