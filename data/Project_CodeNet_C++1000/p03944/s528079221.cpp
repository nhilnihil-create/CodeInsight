#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{

  ll w,h,n,x[110],y[110],a[110];


  cin>>w>>h>>n;
  rep(i,n){
    cin>>x[i]>>y[i]>>a[i];
  }
  ll area[w][h]={0};


  rep(i,n){
    switch(a[i]){
      case 1:
      rep(j,x[i]){
        rep(k,h){
          if(area[j][k]==0)area[j][k]=1;
        }
      }
      break;

      case 2:
      for(int j=w-1;j>=x[i];j--){
        rep(k,h){
          if(area[j][k]==0)area[j][k]=1;
        }
      }
      break;

      case 3:
      rep(j,y[i]){
        rep(k,w){
          if(area[k][j]==0)area[k][j]=1;
        }
      }
      break;

      case 4:
      for(int j=h-1;j>=y[i];j--){
        rep(k,w){
          if(area[k][j]==0)area[k][j]=1;
        }
      }
      break;
    }
  }


  ll ans=0;
  rep(i,w){
    rep(j,h){
      if(area[i][j]==0)ans++;
    }
  }


  cout<<ans<<endl;
  return 0;
}
