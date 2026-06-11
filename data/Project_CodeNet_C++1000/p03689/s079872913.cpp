#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int H,W,h,w;
int a[510][510];

int main(){
  cin >> H >> W >> h >> w;
  int sum=0;
  if(H%h==0 && W%w==0){
    cout << "No" << endl;
  }else{
    if(H%h!=0){
      rep(i,1,H+1) rep(j,1,W+1){
        if(i%h==1) a[i][j] = 10000;
        if(i%h==0) a[i][j] = -10001;
      }
    }else{
      rep(i,1,H+1) rep(j,1,W+1){
        if(j%w==1) a[i][j] = 10000;
        if(j%w==0) a[i][j] = -10001;
      }
    }
    cout << "Yes" << endl;
    rep(i,1,H+1){
      rep(j,1,W+1){
        if(j!=1)cout << " ";
        cout << a[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
