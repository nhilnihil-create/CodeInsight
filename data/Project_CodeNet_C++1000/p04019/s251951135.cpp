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
  map<char, int> amap;
  for(int i=0;i<S.size();++i) {
    amap[S[i]]++;
  }
  bool can = true;
  if(amap['N']>0 && amap['S']==0) can = false;
  if(amap['S']>0 && amap['N']==0) can = false;
  if(amap['W']>0 && amap['E']==0) can = false;
  if(amap['E']>0 && amap['W']==0) can = false;
  if(can) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

