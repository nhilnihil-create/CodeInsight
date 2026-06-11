#include <bits/stdc++.h>
using namespace std;

#define INF 100000
 
int main(){
  vector<vector<int>> table(500, vector<int>(500, INF));
  int n, ma, mb;
  cin >> n >> ma >> mb;
  int a[n], b[n], c[n];
  int asum = 0, bsum = 0;
  table[0][0] = 0;
  for(int i=0; i<n; i++){
    cin >> a[i] >> b[i] >> c[i];
    asum += a[i];
    bsum += b[i];
    for(int j=asum; j>=0; j--){
      for(int k=bsum; k>=0; k--){
        if(table[j][k]==INF) continue;
        table[j+a[i]][k+b[i]] = min(table[j][k]+c[i], table[j+a[i]][k+b[i]]);
      }
    }
  }
  int ans = INF;
  for(int i=1; i<500; i++){
    for(int j=1; j<500; j++){
      if(ma*j==mb*i) ans = min(ans, table[i][j]);
    }
  }
  if(ans==INF) ans = -1;
  cout << ans << endl;
  return 0;
}