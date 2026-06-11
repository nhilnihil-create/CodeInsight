#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string S;
  cin>>S;
  string code="CODEFESTIVAL2016";
  int ans=0;
  for(int i=0;i<S.size();i++){
    if(S[i]!=code[i])ans++;
  }
  cout<<ans<<endl;
  return 0;
}
