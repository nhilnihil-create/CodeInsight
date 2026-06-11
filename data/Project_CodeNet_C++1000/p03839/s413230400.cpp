#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i,s,n) for(int i=s;i<n;i++)
const long long LINF=1e18;
template<typename T>
void chmax(T &a,T b){
  if(a<b)a=b;
}

signed main(){
  int n,k;cin>>n>>k;
  vector<int> v(n),w(n+1,0),se(n+1,0);
  REP(i,0,n)cin>>v[i];
  REP(i,0,n)w[i+1]=w[i]+v[i];
  REP(i,0,n)se[i+1]=se[i]+max(v[i],0LL);
  int ans=-LINF;
  REP(i,0,n-k+1)chmax(ans,se[i]-se[0]+se[n]-se[i+k]+max(w[i+k]-w[i],0LL));
  cout<<ans<<endl;
}
