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
  int w,h,n;
  cin >> w >> h >> n;
  int x1=0,x2=w,y1=0,y2=h;

  rep(i,n){
    int x,y,a; cin >> x >> y >> a;
    if(a==1){
      x1 = max(x1,x);
    }else if(a==2){
      x2 = min(x2,x);
    }else if(a==3){
      y1 = max(y1,y);
    }else if(a==4){
      y2 = min(y2,y);
    }
  }

  if(x1>x2 || y1>y2) puts("0");
  else cout << (x2-x1)*(y2-y1);

}
