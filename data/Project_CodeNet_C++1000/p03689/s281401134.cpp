#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

int A[505][505];

int main(){
  int H,W,h,w; cin>>H>>W>>h>>w;
  if(H%h==0&&W%w==0){
    cout<<"No\n";
    return 0;
  }
  ll a=(1e9-1)/(h*w-1);
  rep(i,H) rep(j,W){
    if(i%h==h-1&&j%w==w-1) A[i][j]=-(a*(h*w-1)+1);
    else A[i][j]=a;
  }

  cout<<"Yes\n";
  rep(i,H){
    rep(j,W) cout<<A[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}
