#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,m;
  cin>>n>>m;
  int a[m],b[m];
  ll c[m];
  rep(i,0,m){
    cin>>a[i]>>b[i]>>c[i];
    a[i]--;
    b[i]--;
  }
  ll d[n];
  rep(i,0,n){
    d[i]=-1e12;
  }
  d[0]=0;
  rep(j,0,n){
    rep(i,0,m){
      if(d[a[i]]!=-1e12 && d[b[i]]<d[a[i]]+c[i]){
        d[b[i]]=d[a[i]]+c[i];
      }
    }
  }
  ll ans=d[n-1];
  rep(i,0,m){
    if(d[a[i]]!=-1e12 && d[b[i]]<d[a[i]]+c[i]){
      d[b[i]]=d[a[i]]+c[i];
    }
  }
  if(ans==d[n-1]) cout<<d[n-1]<<endl;
  else cout<<"inf"<<endl;
}