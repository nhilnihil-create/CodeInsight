#include<bits/stdc++.h>
using namespace std;

int n,m;
long long d[105][105],D[105][105];

void warshall_floyd() {
  for (int k = 0; k < n; k++){       // 経由する頂点
    for (int i = 0; i < n; i++) {    // 始点
      for (int j = 0; j < n; j++) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<=n;++i){
        for(int j=0;j<=n;++j){
            d[i][j]=1e9;
            D[i][j]=1e9;
        }
    }
    for(int i=0;i<m;++i){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        d[a][b]=c;
        d[b][a]=c;
        D[a][b]=c;
        D[b][a]=c;
    }
    warshall_floyd();
    int cnt=0;
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            if(i!=j&&d[i][j]==D[i][j])cnt++;
        }
    }
    cout<<m-cnt<<endl;
}
