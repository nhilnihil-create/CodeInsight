#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  string s;
  cin >> s;
  int size=s.size();
  stack<char> st;
  for(int i=0;i<size;i++){
    if(s.at(i)!='B')
    st.push(s.at(i));
    else if(!st.empty() && s.at(i)=='B')
    st.pop();
  }
  int si=st.size();
  vector<char> v(si);
  for(int i=si-1;i>=0;i--){
    v.at(i)=st.top();
    st.pop();
  }
  for(int i=0;i<si;i++){
    cout << v.at(i);
  }
  cout << endl;
}

