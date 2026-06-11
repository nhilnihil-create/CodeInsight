#include<bits/stdc++.h>
using namespace std;
#define int long
#define pi pair<bool,int>
main(){
  int w,h,s=0,x=0,y=0;
  cin>>w>>h;
  vector<int> p(w),q(h);
  vector<pi> r(w+h);
  for(int i=0;i<w;++i){
    cin>>r[i].second;
    r[i].first=false;
  }
  for(int i=w;i<h+w;++i){
    cin>>r[i].second;
    r[i].first=true;
  }
  sort(r.begin(),r.end(),[](pi a,pi b){return a.second<b.second;});
  for(auto& d:r)s+=d.second*(d.first?(x++,w+1-y):(y++,h+1-x));
  cout<<s;
}
