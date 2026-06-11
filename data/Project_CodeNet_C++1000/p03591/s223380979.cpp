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

  string s;
  cin>>s;
  string y="YAKI";
  bool ok=true;
  for(int i=0;i<4;i++)if(s[i]!=y[i])ok=false;
  if(ok)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
