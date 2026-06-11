#include<bits/stdc++.h> 
using namespace std;
int main()
  {
    string s; cin>>s; 
  int l = s.length(); set<char> st;
  for(auto ch:s)st.insert(ch);
  if(st.size()==l)cout<<"yes";
  else cout<<"no";
  }
