#include<bits/stdc++.h>
using namespace std;
int r;
long long int d[205][205];
int x[8],y[8];
long long int ans=1e18;
void solve(int num,long long int tmp){
    if(num==r || tmp>ans)ans=min(ans,tmp);
    if(num==0){
        for(int i=0;i<r;i++){
            y[0]=i;
            solve(1,0);
        }
    }
    else{
        int z[r];
        for(int i=0;i<r;i++)z[i]=0;
        for(int i=0;i<num;i++)z[y[i]]=1;
        for(int i=0;i<r;i++){
            if(z[i]==0){
                y[num]=i;
                solve(num+1,tmp+d[x[y[num-1]]][x[y[num]]]);
            }
        }        
    }
}

int main(){
    int n,m;
    cin >> n >> m >> r;
    for(int i=0;i<r;i++){
        cin >> x[i];
        x[i]--;
    }
    long long int a,b,c;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)d[i][j]=1e9;
    for(int i=0;i<n;i++)d[i][i]=0;
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        a--; b--;
        d[a][b]=c; d[b][a]=c;
    }
  for (int k = 0; k < n; k++){       // 経由する頂点
    for (int i = 0; i < n; i++) {    // 始点
      for (int j = 0; j < n; j++) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
    solve(0,0);
    cout << ans;
}