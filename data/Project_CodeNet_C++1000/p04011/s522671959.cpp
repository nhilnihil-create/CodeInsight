#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  int n,k,x,y;
  cin>>n>>k>>x>>y;
  if(n<=k) cout<<n*x<<endl;
  else cout<<k*x+(n-k)*y<<endl;
  return 0;
}