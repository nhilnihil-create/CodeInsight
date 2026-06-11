 #include <bits/stdc++.h>
using namespace std; 
#define int int64_t
#define itn int
#define fi first
#define se second
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  int ans=0,sum;
  cin>>s;
  for(int i=0;i<(1<<s.size());i++){
    sum=0;
    for(int j=0;j<s.size();j++){
      //sum+=(s[j]-'0');
      if(i&(1<<j)) ans+=sum,sum=0;
      else sum*=10,sum+=(s[j]-'0');
    }
    ans+=sum;
  }
  cout<<ans<<"\n";
}
