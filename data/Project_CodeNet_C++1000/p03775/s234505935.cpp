#include <bits/stdc++.h>
using namespace std; 
#define int int64_t
#define itn int
#define fi first
#define se second 
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,sum=0,ans=100;
  vector<int> ret;
  cin>>n;
  for(int i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  for(int i=0;i<ret.size();i++){
    int a=0,b=0,c=n/ret[i];
    while(true){
      if(c==0) break;
      a++;
      c/=10;
    }
    while(true){
      if(ret[i]==0) break;
      ret[i]/=10;
      b++;
    }
    ans=min(ans,max(a,b));
  }
  cout<<ans<<"\n";
}
  
