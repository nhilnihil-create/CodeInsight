#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  
  int n=s.size();
  vector<int> A(n);
  rep(i,n) A[i]=s[n-1-i]-'0';
  
  ll ans=0;
  for(int bit=0;bit<(1<<(n-1));bit++){
    ll c=1;
    for(int i=0;i<n;i++){
      ans+=c*A[i];
      if(bit&(1<<i)){
        c=1;
        continue;
      }
      c*=10;
    }
  }
  cout<<ans<<endl;
  
  return 0;
}