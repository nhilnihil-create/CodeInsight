#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
  cin>>s;
  int n=s.length();
  stack<char> st;
  for(int i=0;i<n;i++){
  	if(s[i]=='B'){
      if(!st.empty())st.pop();
    }
    else st.push(s[i]);
  }
  string g="";
  while(!st.empty()){
    g+= string(1,st.top());
    st.pop();
  }
  reverse(g.begin(),g.end());
  cout<<g<<endl;
}