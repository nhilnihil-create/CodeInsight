#include <bits/stdc++.h>
using namespace std;

signed main(){
  int n,m;cin>>n>>m;
  vector<int> ball(n,1);
  vector<int> re(n,0);
  re[0]++;
  while(m--){
    int x,y;cin>>x>>y;x--;y--;
    re[y]|=re[x];
    ball[x]--;ball[y]++;
    if(!ball[x])re[x]=0;
  }
  int ans=0;
  for(int i=0;i<n;i++)ans+=re[i];
  cout<<ans<<endl;
}
