#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;


int main() {
  int h,w,n;
  cin >> h >>w >>n;
  int a[n];
  rep(i,n)cin >> a[i];
  int k=0;
  int ans[h][w];

  rep(i,h){
    if((i+2)%2==0){
      rep(j,w){
        if(a[k]==0)k++;
        if(a[k]>=0){ans[i][j]=k+1;a[k]--;}
      }
    }else{
      for(int j=w-1;j>=0;j--){
        if(a[k]==0)k++;
        if(a[k]>=0){ans[i][j]=k+1;a[k]--;}
      }
    }
  }

  rep(i,h){
    rep(j,w)cout << ans[i][j] << " ";
    cout << endl;
  }
}
