#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)j; i<(int)n; i++)
int main() {
  const int MAX_NM=50,MAX_DIST=200000000;
  int n,m,a[MAX_NM],b[MAX_NM],c[MAX_NM],d[MAX_NM];

  cin>>n>>m;
  rep(i,0,n) cin>>a[i]>>b[i];
  rep(i,0,m) cin>>c[i]>>d[i];

  rep(i,0,n){
    int dist=MAX_DIST,nearest=1;
    rep(j,0,m){
      int currentdist=abs(a[i]-c[j])+abs(b[i]-d[j]);
      if(dist>currentdist){
        dist=currentdist;
        nearest=j+1;
      }
    }
    cout<<nearest<<endl;
  }
}