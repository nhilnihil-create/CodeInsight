#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  string S;
  cin>>S;
  bool s=false, e=false, n=false, w=false;
  for(int i=0;i<S.size();++i) {
    if(S[i]=='S') s = true;
    if(S[i]=='E') e = true;
    if(S[i]=='N') n = true;
    if(S[i]=='W') w = true;
  }
  if((s^n) || (e^w)) cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}

