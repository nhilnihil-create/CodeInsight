#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
 
int main(){
  int n,m;
  cin>>n>>m;
  vector<pair<int,int>> p(n);
  rep(i,n) cin>>p[i].first>>p[i].second;
  vector<pair<int,int>> t(m);
  rep(i,m){
    cin>>t[i].first>>t[i].second;
  }
  rep(i,n){
    int cnt=0;
    int cnt2=INF;
    int ans=0;
    rep(j,m){
      cnt=abs(p[i].first-t[j].first)+abs(p[i].second-t[j].second);
      if(cnt2>cnt){
        cnt2=cnt;
        ans=j+1;
      }
    }
    cout<<ans<<endl;
  }
}
