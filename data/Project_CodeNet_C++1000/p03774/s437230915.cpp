#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,m;
  cin>>n>>m;
  int a[n];
  int b[n];
  rep(i,0,n) cin>>a[i]>>b[i];
  int c[m];
  int d[m];
  rep(i,0,m) cin>>c[i]>>d[i];
  rep(i,0,n){
    int point=-1;
    int res=3e8;
    rep(j,0,m){
      if(abs(a[i]-c[j])+abs(b[i]-d[j])<res){
        point=j;
        res=abs(a[i]-c[j])+abs(b[i]-d[j]);
      }
    }
    cout<<point+1<<endl;
  }
}