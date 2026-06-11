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
  ll len = S.size();
  vector<char> arr;
  map<char, ll> amap;
  for(ll i=0;i<len;++i) {
    if(amap[S[i]]==0) arr.push_back(S[i]);
    amap[S[i]]++;
  }
  ll ans = len*(len-1)/2;
  for(ll i=0;i<arr.size();++i) {
    ans -= amap[arr[i]]*(amap[arr[i]]-1)/2;
  }
  cout<<ans+1<<endl;
}

