#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t;
  cin>>s>>t;
  vector<int> ss(s.size()+1,0);
  vector<int> st(t.size()+1,0);
  for(int i=0;i<s.size();i++)
    ss.at(i+1)=ss.at(i)+(s.at(i)=='A'?1:2);
  for(int i=0;i<t.size();i++)
    st.at(i+1)=st.at(i)+(t.at(i)=='A'?1:2);
  int q;
  cin>>q;
  for(int _=0;_<q;_++){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<((ss.at(b)-ss.at(a-1))%3==(st.at(d)-st.at(c-1))%3?"YES":"NO")<<endl;
  }
}