#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;


int main(){
  ll w,h,n;
  cin >> w >> h >> n;

  std::vector<int> x(n);
  std::vector<int> y(n);
  int a;
  ll light=0,right=w,botom=0,top=h;
  rep(i,n){
    cin >> x.at(i) >> y.at(i) >> a;
    if(a==1){
      if(light<x.at(i)){
      light=x.at(i);
      }
    }
    if(a==2){
      if(right>x.at(i)){
      right=x.at(i);
      }
    }
    if(a==3){
      if(botom<y.at(i)){
        botom=y.at(i);
      }
    }
    if(a==4){
      if(top>y.at(i)){
        top=y.at(i);
      }
    }
  }

  int ans,W,H;
  W=right-light;
  H=top-botom;
 if(top<=botom || right<=light){
    W=0; H=0;
  }

  ans=W*H;


  cout << ans << endl;


  }