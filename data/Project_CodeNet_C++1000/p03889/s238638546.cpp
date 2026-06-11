//666yuchen
#include<bits/stdc++.h>
using namespace std;
string st;
char b[500];
int main()
{
  cin>>st;
  b['b']='d';b['d']='b';b['p']='q';b['q']='p';
  for(int i=0;i<st.size();i++)if(b[st[i]]!=st[st.size()-1-i]){cout<<"No"<<endl;return 0;}
  cout<<"Yes"<<endl;
  return 0;
}