#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int V,E;
  cin >> V >> E;
  vector<int>a(E);
  vector<int>b(E);
  vector<int>c(E);
  vector<vector<int>>d(V, vector<int>(V,100000000));
  for (int i=0;i<E;i++) {
    cin >> a.at(i) >> b.at(i) >> c.at(i);
    d[a[i]-1][b[i]-1]=c[i];
    d[b[i]-1][a[i]-1]=c[i];
  }
  for (int i=0;i<V;i++) {
    d[i][i]=0; 
  }
  for(int k=0;k<V;k++) {
    for (int i=0;i<V;i++) {
      for (int j=0;j<V;j++) {
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        d[j][i]=d[i][j];
      }
    }
  }
  int ans=E;
  for (int i=0;i<E;i++) {
    for (int j=0;j<V;j++) {
      if(d[j][a[i]-1]+c[i]==d[j][b[i]-1]){
        ans--;
        break;
      }      
    }
  }
  cout << ans << endl;
}