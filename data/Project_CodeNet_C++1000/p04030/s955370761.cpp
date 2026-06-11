#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char **argv)
{
	string s;
  cin>>s;
  stack <char> stacky;
  for(ll i=0;i<s.size();i++){
    if (s[i]=='1'||s[i]=='0') stacky.push(s[i]);
    else if (s[i]=='B'){
      if (!stacky.empty()) stacky.pop();
    }
    }
  string ans="";
  while (!(stacky.empty())){
    ans+=stacky.top();
    stacky.pop();
  }
  reverse(ans.begin(),ans.end());
  cout<<ans<<"\n";
  
	return 0;
}
