#include <bits/stdc++.h>

#define rep(i, n) for(int i=0; i < n; i++)
#define reps(i, n) for(int i=1; i <= n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define rALL(x) x.rbegin(),x.rend()

using namespace std;
using ll=long long;


int main(){
  int k,s;cin>>k>>s;
  int ans=0;
  rep(x,min((k+1),s+1)){
    int rem=s-x;
    rep(y,min(k+1,rem+1)){
      int rem2=rem-y;
      if(rem2>=0&&rem2<k+1)ans++;
    }
  }
  cout<<ans;
}