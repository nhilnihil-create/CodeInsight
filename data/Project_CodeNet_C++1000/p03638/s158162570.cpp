#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int h,w,n;
  cin>>h>>w>>n;
  int a[n];
  rep(i,0,n) cin>>a[i];
  int b[h][w];
  int k=0;
  rep(i,0,h){
    rep(j,0,w){
      if(i%2==0){
        b[i][j]=k+1;
      }
      else{
        b[i][w-1-j]=k+1;
      }
      a[k]--;
      if(a[k]==0){
        k++;
      }
    }
  }
  rep(i,0,h){
    rep(j,0,w){
      cout<<b[i][j];
      if(j==w-1) cout<<endl;
      else cout<<' ';
    }
  }
}