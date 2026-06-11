#include "bits/stdc++.h"
using namespace std;
#define int long long
int mod=1e9+7;

signed main(){
  int w,h;
  cin>>w>>h;
  vector<pair<int,int> > pq;
  for(int i=0;i<w;i++){
    int a;
    cin>>a;
    pq.push_back(make_pair(a,0));
  }
  for(int i=0;i<h;i++){
    int a;
    cin>>a;
    pq.push_back(make_pair(a,1));
  }
  sort(pq.begin(),pq.end());
  int ans=0;
  int x=w+1;
  int y=h+1;
  for(int j=0;j<pq.size();j++){
    if(pq[j].second==0){
      ans+=y*pq[j].first;
      x--;
    }else{
      ans+=x*pq[j].first;
      y--;
    }
  }
  cout<<ans<<endl;
}
