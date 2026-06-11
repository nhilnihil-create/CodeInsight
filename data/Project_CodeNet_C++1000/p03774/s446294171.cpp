#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n,m; cin >>n >>m;
  int a[50], b[50], c[50], d[50];
  rep(i,n) cin >>a[i] >>b[i];
  rep(i,m) cin >>c[i] >>d[i];
  rep(i,n){
    int min_dist = abs(a[i]-c[0])+abs(b[i]-d[0]), checkpoint = 1;
    for(int j = 1; j<m; j++){
      const int cur_dist = abs(a[i]-c[j])+abs(b[i]-d[j]);
      if(min_dist>cur_dist){
        min_dist=cur_dist;
        checkpoint=j+1;
      }
    }
    cout << checkpoint << endl;
  }
  return 0; 
}