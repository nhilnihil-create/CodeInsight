#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int a,b,c,d,e,f;
  cin>>a>>b>>c>>d>>e>>f;
  bool p[3000+1];
  rep(i,0,3000+1) p[i]=false;
  int i=0;
  while(i<=3000){
    int j=i;
    while(j<=3000){
      p[j]=true;
      j+=d;
    }
    i+=c;
  }
  vector<int> q;
  rep(i,0,3000+1){
    if(p[i]) q.push_back(i);
  }
  int water=0;
  int sugar=0;
  int cur=-1;
  rep(i,0,30){
    rep(j,0,30){
      if(100*(a*i+b*j)<=f && i+j!=0){
        auto it=upper_bound(q.begin(),q.end(),min(f-100*(a*i+b*j),(a*i+b*j)*e));
        it--;
        if(*it/(a*i+b*j)>cur){
          sugar=*it;
          water=a*i+b*j;
          cur=*it/(a*i+b*j);
        }
      }
    }
  }
  cout<<100*water+sugar<<' '<<sugar<<endl;
}