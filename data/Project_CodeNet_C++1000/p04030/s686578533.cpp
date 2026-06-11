#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{

  string s;
  cin>>s;
  string ans="\0";
  rep(i,s.length()){
    if(s[i]=='0')ans.append("0");
    if(s[i]=='1')ans.append("1");
    if(s[i]=='B'&&ans.length()>0)ans.erase(ans.length()-1);
  }
  cout<<ans<<endl;
  return 0;
}
