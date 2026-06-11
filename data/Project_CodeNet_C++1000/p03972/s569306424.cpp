#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int w,h;
  cin>>w>>h;
  vector<P>v;
  rep(i,w){
    int x; cin>>x;
    v.push_back(P(x,0));
  }
  rep(i,h){
    int x; cin>>x;
    v.push_back(P(x,1));
  }
  sort(v.begin(),v.end());
  w++; h++;
  ll ans=0;
  rep(i,v.size()){
    if(v[i].second==1)ans+=(ll)w*v[i].first,h--;
    else ans+=(ll)h*v[i].first,w--;
  }
  cout<<ans<<endl;
}