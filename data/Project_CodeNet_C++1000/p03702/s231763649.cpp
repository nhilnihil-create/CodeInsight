#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  int N,A,B;
  cin>>N>>A>>B;
  std::vector<int> v(N);
  for(int i=0;i<N;i++)cin>>v[i];
  sort(v.begin(),v.end());//いらなかった
  int l=0;int r=1e9+7;
  while(r-l>1){
    int m=(l+r)/2;
    //cout<<l<<" "<<r<<" "<<m<<" ";
    std::vector<int> c(N);
    for(int i=0;i<N;i++)c[i]=v[i];
    for(int i=0;i<N;i++)c[i]-=m*B;
    int bb=0;
    for(int i=0;i<N;i++){
      if(c[i]>0){
        bb+=c[i]/(A-B);
        if(c[i]%(A-B))bb++;
      }
    }
    //cout<<bb<<endl;
    if(bb<=m)r=m;
    else l=m;
  }
  cout<<r<<endl;
}
