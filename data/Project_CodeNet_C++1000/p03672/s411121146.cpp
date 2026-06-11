#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define fi first
#define se second
#define INF 1000000009
#define LLINF 1000000000000000009LL
using ll = long long;

int main(){
  string s;
  cin>>s;
  int m=s.size();
  rep(j,m){
    s.pop_back();
    bool ok=true;
    int n=s.size();
    if(n%2==1)continue;
    rep(i,n/2){
      if(s[i]!=s[n/2+i])ok=false;
    }
    if(ok){
      cout<<n<<endl;
      return(0);
    }
  }
  return(0);
}
