#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n,m;
  cin >> n >> m;
  
  string a[n],b[m];
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];
  
  int ans = 0;
  for(int h = 0; h <= n-m; h++){   
    for(int w = 0; w <= n-m; w++){
      for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
          if(a[h+i][w+j] == b[i][j]){
            ans++;
          }//if
        }//for
      }//for
      if(ans == m * m){
        cout << "Yes" << endl;
        return 0;
      }
      ans = 0;
    }//for
  }//for

  cout << "No" << endl;
}