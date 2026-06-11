#include <bits/stdc++.h>
#define rep(i,m,n) for(int i=m; i<n; i++)
#define co(n) cout << n << endl
using namespace std;
int main(){
  char s='A', k;
  int h, w;
  cin >> h >> w;
  string a[h][w];
  rep(i,0,h){
    rep(j,0,w) cin >> a[i][j];
  }
  
  rep(i,0,h){
    rep(j,0,w){
      if(a[i][j]=="snuke"){
        k=s+j;
        cout << k << i+1 << endl;
      }
    }
  }
  
  
  return 0;
}
