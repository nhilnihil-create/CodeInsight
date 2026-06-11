#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  int t[n];
  for(int i = 1; i <= n; i++) cin >> t[i];
  
  int m;
  cin >> m;
  int p[m+1],x[m+1];
  for(int i = 1; i <= m; i++) cin >> p[i] >> x[i];
  
  int ans[m+1] = {0};
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      if(j == p[i]){
        ans[i] += x[i];
      }else{
        ans[i] += t[j];
      }
    }
  }
  
  for(int i = 1; i <= m; i++){
    cout << ans[i] << endl;
  }
      
}