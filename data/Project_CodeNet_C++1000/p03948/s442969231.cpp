#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,x,n) for(int i=(x);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define int long long
using namespace std;
const int MOD=1e9+7;
const int INF=1e10;
template<typename T> void cmax(T &a, T b) {a = max(a, b);}
template<typename T> void cmin(T &a, T b) {a = min(a, b);}



signed main(){
  int n,t;
  cin>>n>>t;
  vector<int> a(n);
  rep(i,n)cin>>a[i];
  int high=a[0],low=a[0];
  map<int,int> mp;
  int range=-INF;
  loop(i,1,n){
    if(a[i]>high){
      high=a[i];
      mp[high-low]++;
      cmax(range,high-low);
    }
    if(a[i]<low){
      high=low=a[i];
    }
  }

  cout<<mp[range]<<endl;

  return 0;
}
