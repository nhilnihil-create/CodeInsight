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
  int n;
  cin>>n;
  map<int,int> mp;
  rep(i,n){
    int p;
    cin>>p;
    mp[p-1]++; mp[p]++; mp[p+1]++;
  }
  int ans=0;
  for(auto x:mp){
    ans=max(ans,x.second);
  }
  cout<<ans<<endl;
}
