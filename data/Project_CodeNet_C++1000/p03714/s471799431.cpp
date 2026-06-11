#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,z,j;
  int64_t ans=-1e14;
  cin>>n;
  multiset<int> p,m;
  vector<int64_t> x(n),ps(n+1),ms(n+1);
  for(j=0;j<3*n;j++){
    cin>>z;
    if(j<n){
      p.insert(z);
      ps.at(0)+=z;
    }
    else if(j<2*n) x.at(j-n)=z;
    else if(j<3*n){
      m.insert(z);
      ms.at(0)+=z;
    }
  }
  for(j=0;j<n;j++){
    if(x.at(j)>*p.begin()){
      ps.at(j+1)=ps.at(j)+x.at(j)-*p.begin();
      p.erase(p.begin());
      p.insert(x.at(j));
    }
    else ps.at(j+1)=ps.at(j);
    if(x.at(n-1-j)<*prev(m.end(),1)){
      ms.at(j+1)=ms.at(j)+x.at(n-1-j)-*prev(m.end(),1);
      m.erase(prev(m.end(),1));
      m.insert(x.at(n-1-j));
    }
    else ms.at(j+1)=ms.at(j);
  }
  for(j=0;j<=n;j++) ans=max(ans,ps.at(j)-ms.at(n-j));
  cout<<ans<<endl;
}