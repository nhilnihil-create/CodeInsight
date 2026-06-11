#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1e9+7;

double mkaijo(int n){
  if(n<=1) return 1;
  return n*mkaijo(n-1);
}

int main() {
  long long n,a,b;
  cin>>n>>a>>b;
  vector<long long> X(n);
  rep(i,n) cin>>X[i];
  /*a,b,c(a<b<c)の部分について考えると
  aからbにテレポートしても、aからcにテレポートしても変わらない
  よって常に東に進む時を考える*/
  long long ans=0;
  rep(i,n-1) ans+=min(a*(X[i+1]-X[i]),b);
  cout<<ans<<endl;
  return 0;
}