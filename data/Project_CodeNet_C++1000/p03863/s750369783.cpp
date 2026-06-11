//666yuchen
//超过AC80
#include<bits/stdc++.h>
using namespace std;
string st;
int main()
{
  cin>>st;
  if(st[0]==st[st.size()-1])
  {
  	if(st.size()%2==0)cout<<"First";
  	else cout<<"Second";
  }
  else
  {
  	if(st.size()%2==0)cout<<"Second";
  	else cout<<"First";
  }
  cout<<endl;
  return 0;
}