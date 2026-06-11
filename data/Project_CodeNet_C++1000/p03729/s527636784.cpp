#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  string a,b,c;
  cin>>a>>b>>c;
  int la=a.size(),lb=b.size(),lc=c.size();
  if(a[la-1]==b[0] && b[lb-1]==c[0]) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}