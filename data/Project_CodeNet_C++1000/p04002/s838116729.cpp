#include <bits/stdc++.h>
using namespace std;
#define int long long
 // queue<pair<int,int>> que;
signed main() {
  int h,w,n;
  cin>>h>>w>>n;
  map<pair<int,int>,int> mp;
  int a,b;
  for(int i=0;i<n;i++){
    cin>>a>>b;
    for(int j=0;j<=2;j++){
      for(int u=0;u<=2;u++){
        if(a-j>0&&b-u>0&&a-j<=h-2&&b-u<=w-2)mp[make_pair(a-j,b-u)]++;
      }
    }

  }
  int ans[10]={};
  ans[0]=(h-2)*(w-2);
  for(auto itr=mp.begin();itr!=mp.end();++itr){
    ans[itr->second]++;
    //cerr<<itr->first.first<<' '<<itr->first.second<<' '<<itr->second<<endl;
    ans[0]--;
  }
  for(int i=0;i<10;i++)cout<<ans[i]<<endl;
  return 0;
}
