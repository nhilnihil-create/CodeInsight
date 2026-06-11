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
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N;
  cin>>N;
  vector<int> arr(N);
  for(int i=0;i<N;++i) cin>>arr[i];
  sort(arr.begin(), arr.end(), greater<int>());
  int minnum = (arr[0]+1)/2;
  map<int, int> amap;
  vector<int> aru;
  for(int i=0;i<N;++i) {
    if(amap[arr[i]]==0) aru.push_back(arr[i]);
    amap[arr[i]]++;
  }
  sort(aru.begin(), aru.end());
  bool can = true;
  for(int i=minnum;i<=arr[0];++i) {
    if(i==minnum)  {
      if(arr[0]%2==0) {
        if(amap[i]!=1) can = false;
      }
      else {
        if(amap[i]!=2) can = false;
      }
    }
    else {
      if(amap[i]<2) can = false;
    }
  }
  if(can) cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
}

