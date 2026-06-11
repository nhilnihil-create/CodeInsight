#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
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
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  string S;
  cin>>S;
  map<char, int> amap;
  bool ok = true;
  for(int i=0;i<S.size();++i){
    if(amap[S[i]]>0) ok = false;
    amap[S[i]]++;
  }
  if(ok) cout<<"yes"<<endl;
  else cout<<"no"<<endl;
}

