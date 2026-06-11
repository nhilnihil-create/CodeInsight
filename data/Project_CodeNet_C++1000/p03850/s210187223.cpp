//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
#define int long long
   template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
    const int MAX =1002;
const int MOD =1000000007;

signed main(){
  int n,a,b,x;
  cin>>n>>a;b=a;
  vector<int> v,w;
  char c;
  for(int i=1;i<n;i++){
    cin>>c>>x;
    if(c=='+'){
      a+=x;
      b+=x;continue;
    }
    v.push_back(a);
    w.push_back(b);
    a=x;b=-x;
  }
  v.push_back(a);
    w.push_back(b);
    int ans[3]={};
  for(int i=v.size()-1;i>=0;i--){
    ans[2]=w[i]+max(ans[2],ans[1]);
    ans[1]=ans[0]-v[i];
    ans[0]+=v[i];
  }
  cout<<ans[2]<<endl;
}