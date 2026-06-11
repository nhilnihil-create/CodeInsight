#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int w,h,p;
  vector< pair<int,int> > v;
  cin>>w>>h;
  for(int i=0;i<w;i++)cin>>p,v.push_back(make_pair(p,1));
  for(int i=0;i<h;i++)cin>>p,v.push_back(make_pair(p,2));
  sort(v.begin(),v.end());
  w++,h++;
  int ans=0;
  for(int i=0;i<v.size();i++){
    if(v[i].second==1){
      ans+=v[i].first*h;
      w--;
    }else{
      ans+=v[i].first*w;
      h--;
    }
  }
  cout<<ans<<endl;
  return 0;
}
