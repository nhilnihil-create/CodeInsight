#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>
#include<stack>

using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
using lint=long long;
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
signed main(){  
  int n;cin>>n;
  vector<int> x(n);
  rep(i,n)cin>>x[i];
  stack<int> st;
  lint res=1;
  rep(i,n){
      st.push(x[i]);
      if(x[i]<st.size()*2-1){
          res*=st.size();
          st.pop();
      }
      res%=MOD;
  }
  int num=st.size();
  rep1(i,num){
      res*=i;res%=MOD;
  }
  cout<<res<<"\n";
  return 0;
}