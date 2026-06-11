#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=0;i<(n);i++)
#define lps(i,j,n) for(int i=j;i<n;i++)
#define fordebug int hoge;cin>>hoge;
#define DEKAI 1000000007
#define INF 2000000000000
#define int long long
#define double long double
#define floot10 cout<<fixed<<setprecision(10)
#define Int long long
#define hogea pair<pair<int,int>,int>

signed main(){
  int h,w,x,y;
  cin>>h>>w>>x>>y;
  int a[510][510];
  lp(i,h){
    lp(j,w){
      a[i][j]=2000;
    }
  }
  int base=(x*y-1)*2000*(-1)-1;
  for(int i=x-1;i<h;i+=x){
    for(int j=y-1;j<w;j+=y){
      a[i][j]=base;
    }
  }
  int suma=0;
  lp(i,h){
    lp(j,w){
      suma+=a[i][j];
    }
  }
  if(suma>0){
    cout<<"Yes"<<endl;
    lp(i,h){
      lp(j,w){
        if(j!=0)cout<<" ";
        cout<<a[i][j];
      }
      cout<<endl;
    }
  }
  else{
    cout<<"No"<<endl;
  }
  return 0;
}
