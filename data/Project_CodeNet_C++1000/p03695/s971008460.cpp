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
  int cnt=0;
  int ans=0;
  int ans2=0;
  rep(i,n){
    int p;
    cin>>p;
    if(1<=p&&p<400) mp[1]++;
    if(400<=p&&p<800) mp[2]++;
    if(800<=p&&p<1200) mp[3]++;
    if(1200<=p&&p<1600) mp[4]++;
    if(1600<=p&&p<2000) mp[5]++;
    if(2000<=p&&p<2400) mp[6]++;
    if(2400<=p&&p<2800) mp[7]++;
    if(2800<=p&&p<3200) mp[8]++;
    if(3200<=p) cnt++;
  }
  ans=mp.size();
  ans2=ans+cnt;
  if(ans==0){
    ans=1;
  }
  cout<<ans<<" "<<ans2<<endl;
}
