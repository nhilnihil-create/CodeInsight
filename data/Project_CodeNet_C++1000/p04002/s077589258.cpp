#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define rep(i,b) FOR(i,0,b)
#define INF 1e9
#define dump(x) cerr<<#x<<"="<<x<<endl
#define all(a) (a).begin(),(a).end()
typedef pair<int,int> P;
template <class T> void chmin(T & a, T const & b) { if (b < a) a = b; }
template <class T> void chmax(T & a, T const & b) { if (b > a) a = b; }
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
using ll = long long;
const ll mod = LLONG_MAX;
#define int long long
int h,w,n;

const int dx[9] = {1, 1, 1, 0, 0, -1, -1, -1,0};
const int dy[9] = {0, 1, -1, 1, -1, 0, 1, -1,0};
map<pair<int,int>,int> mp;
int ans[10];
signed main(){
  cin>>h>>w>>n;
  int cnt=0;

  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;

    for(int j=0;j<9;j++){
      int xt=a+dx[j];
      int yt=b+dy[j];
      if(1<=xt && 1<=yt &&xt<h-1&&yt<w-1){
        // mp.insert(make_pair(xt,yt),);
        //cout<<"xt="<<xt<<" yt="<<yt<<endl;
        cnt++;
        mp[make_pair(xt,yt)]+=1;
      }
    }
  }
  dump(cnt);
  for(auto itr:mp){
    // cout<<itr.first.first<<" "<<itr.first.second<<endl;
    // cout<<itr.second<<endl;
     ans[itr.second]++;
  }
  int total=0;
  for(int i=1;i<10;i++){
    total+=ans[i];
  }
  cout<<(h-2)*(w-2)-total<<endl;
  for(int i=1;i<10;i++){
    cout<<ans[i]<<endl;
  }



}
