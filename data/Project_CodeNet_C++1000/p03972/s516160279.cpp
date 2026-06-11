#include <bits/stdc++.h>
const int INF=1e9,MOD=1e9+7;
const long long LINF=1e18;
using namespace std;
#define int long long
//template
//main
signed main(){
  int H,W;cin>>H>>W;swap(H,W);
  typedef pair<int,int> P;
  std::vector<P> v(H+W);
  for(int i=0;i<W;i++){
    int a;cin>>a;
    v[i]=P(a,1);
  }
  for(int i=0;i<H;i++){
    int a;cin>>a;
    v[W+i]=P(a,0);
  }
  sort(v.begin(),v.end());
  int ans=0;int h=H+1,w=W+1;
  for(int i=0;i<H+W;i++){
    if(v[i].second){
      ans+=h*v[i].first;
      w--;
    }
    else{
      ans+=w*v[i].first;
      h--;
    }
  }
  cout<<ans<<endl;
}
