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
  ll H, W;
  cin>>H>>W;
  ll N;
  cin>>N;
  map<pair<int, int> , int> amap;
  vector<pair<int, int> > arr;
  ll a, b;
  for(int i=0;i<N;++i){
    cin>>a>>b;
    a--;
    b--;
    if(a-2>=0 && b-2>=0){
      if(amap[mp(a-1, b-1)]==0) arr.push_back(mp(a-1, b-1));
      amap[mp(a-1, b-1)]++;
    }
    if(b-1>=0 && a-2>=0 && b+1<W){
      if(amap[mp(a-1, b)]==0) arr.push_back(mp(a-1, b));
      amap[mp(a-1, b)]++;
    }
    if(a-2>=0 && b+2<W){
      if(amap[mp(a-1, b+1)]==0) arr.push_back(mp(a-1, b+1));
      amap[mp(a-1, b+1)]++;
    }
    if(a-1>=0 && a+1<H && b-2>=0){
      if(amap[mp(a, b-1)]==0) arr.push_back(mp(a, b-1));
      amap[mp(a, b-1)]++;
    }
    if(a-1>=0 && a+1<H && b-1>=0 && b+1<W){
      if(amap[mp(a, b)]==0) arr.push_back(mp(a, b));
      amap[mp(a, b)]++;
    }
    if(a-1>=0 && a+1<H && b+2<W){
      if(amap[mp(a, b+1)]==0) arr.push_back(mp(a, b+1));
      amap[mp(a, b+1)]++;
    }
    if(a+2<H && b-2>=0){
      if(amap[mp(a+1, b-1)]==0) arr.push_back(mp(a+1, b-1));
      amap[mp(a+1, b-1)]++;
    }
    if(a+2<H && b-1>=0 && b+1<W){
      if(amap[mp(a+1, b)]==0) arr.push_back(mp(a+1, b));
      amap[mp(a+1, b)]++;
    }
    if(a+2<H && b+2<W){
      if(amap[mp(a+1, b+1)]==0) arr.push_back(mp(a+1, b+1));
      amap[mp(a+1, b+1)]++;
    }
  }
  map<int, int> bmap;
  for(int i=0;i<arr.size();++i){
    bmap[amap[arr[i]]]++;
  }
  ll sum = 0;
  for(int i=1;i<10;++i){
    sum += bmap[i];
  }
  cout<<(H-2)*(W-2)-sum<<endl;
  for(int i=1;i<10;++i){
    cout<<bmap[i]<<endl;
  }
}

