#include<iostream>
#include<cmath>
#include<numeric>
#include<functional>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n;i++)
#define ll long long
#define INF 2147483647
using namespace std;
using Graph=vector<vector<int>>;

int main(){
  int w,h,n; cin>>w>>h>>n;
  int x[n],y[n],a[n];
  int xleft=0,xright=w;
  int ydown=0,yup=h;
  rep(i,n){
    cin>>x[i]>>y[i]>>a[i];
    switch(a[i]){
      case 1:
        xleft=max(xleft,x[i]);
        break;
      case 2:
        xright=min(xright,x[i]);
        break;
      case 3:
        ydown=max(ydown,y[i]);
        break;
      case 4:
        yup=min(yup,y[i]);
    }
  }
  int xrange=max(0,xright-xleft);
  int yrange=max(0,yup-ydown);
  cout<<xrange*yrange;
}
