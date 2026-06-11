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
  int H, W;
  cin>>H>>W;
  map<char, int> amap;
  vector<char> arr;
  char tmp;
  for(int i=0;i<H;++i) {
    for(int j=0;j<W;++j) {
      cin>>tmp;
      if(amap[tmp]==0) arr.push_back(tmp);
      amap[tmp]++;
    }
  }
  bool can = true;
  int onenum=0, twonum=0;
  if(H%2==0 && W%2==0) {
    for(int i=0;i<arr.size();++i) {
      if(amap[arr[i]]%4!=0) can = false;
    }
  }
  if(H%2==1 && W%2==0) {
    for(int i=0;i<arr.size();++i) {
      if(amap[arr[i]]%2!=0) can = false;
      if(amap[arr[i]]%4==2) twonum++;
    }
    if(twonum>W/2) can = false;
  }
  if(H%2==0 && W%2==1) {
    for(int i=0;i<arr.size();++i) {
      if(amap[arr[i]]%2!=0) can = false;
      if(amap[arr[i]]%4==2) twonum++;
    }
    if(twonum>H/2) can = false;
  }
  if(H%2==1 && W%2==1) {
    for(int i=0;i<arr.size();++i) {
      if(amap[arr[i]]%2==1) onenum++;
      if(amap[arr[i]]%4==2) twonum++;
    }
    if(onenum!=1) can = false;
    if(twonum>H/2+W/2) can = false;
  }
  if(can) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

