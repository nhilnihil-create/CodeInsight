#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  map<char,int>a;
  map<char,int>lp;
  set<char>st;
  
  for(int i=0;i<s.length();i++)
  {
    
    a[s[i]]=max((i-lp[s[i]]-1*(a[s[i]]!=0)),a[s[i]]);
    
    lp[s[i]]=i;
    st.insert(s[i]);
  }
  if(st.size()==1)
  {
    cout<<0<<endl;
    return 0;
  }
  //cout<<a['r']<<endl;
  
  int maxm=0;
  char maxc;
  int cur=100;
  vector<int>v(26);
  for(int i=s.length()-1;i>=0;i--)
  {
   	if(v[s[i]-'a'])continue;
    v[s[i]-'a']=1;
    int t=a[s[i]];
    if(a[s[i]]<(s.length()-i-1))t=s.length()-i-1;
    if(cur>t)cur=t;
  }
  cout<<cur<<endl;
  return 0;
}
    
    
    