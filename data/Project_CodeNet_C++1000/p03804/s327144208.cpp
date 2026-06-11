#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main() {
 int n,m; cin >> n >> m;
 vector<string> a(n),b(m);
 rep(i,n)cin >> a[i];
 rep(i,m)cin >> b[i];
 int d=n-m,cnt=0;;
  for(int i=0;i<d+1;i++){
    for(int j=0;j<d+1;j++){
       bool flag=1;
      if(a[i][j]==b[0][0]){
        for(int k=0;k<m;k++){
          for(int l=0;l<m;l++){
            if(a[i+k][j+l]!=b[k][l]){
              flag=0;
              break;
            }
          }
          if(!flag)break;
        }
        if(flag){
          cout << "Yes" <<endl;
          return 0;
        }
        }
      }
    }
     cout << "No" <<endl;
     return 0;
  }