#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	string s;
  cin>>s;
  stack<char>st;
  ll ans=0;
  for(ll i=0;i<s.length();i++)
  {
    if(s[i]=='T')
    {
      if(st.empty())
        ans++;
      else
        st.pop();
    }
    else
    {
      st.push(s[i]);
    }
  }
  ans+=st.size();
  cout<<ans<<endl;
  return 0;
}