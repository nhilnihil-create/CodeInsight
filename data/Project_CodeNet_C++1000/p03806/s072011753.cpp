  #include <iostream>
  #include <string>
  #include <vector>
  #include <algorithm>
  using namespace std;
  typedef long long ll;
  #define rep(i,n) for (int i=0;i < (int)(n);i++)
  const int INF =1 << 30;
  int dp[2][402][402];

  int main(){
    int n,ma,mb;
    cin >> n >> ma >> mb;
    vector<vector<int>> v(n,vector<int> (3));
    rep(i,n){
      int x,y,z;
      cin >> x >> y >> z;
      v[i][0]=x;v[i][1]=y;v[i][2]=z;
    }
    int now=0;
    int nxt=1;
    rep(i,401) rep(j,401) {
      dp[now][i][j]=INF;
      dp[nxt][i][j]=INF;
    }
    //printf("ok\n");
    dp[now][0][0]=0;
    dp[nxt][0][0]=0;
    rep(i,n){
      for (int x=0;x <= 400;x++){
        for (int y=0;y <= 400;y++){
          //if (i > 2 || x >= 400 || y >= 400) printf("i=%d x = %d y = %d\n",i,x,y);
          if (dp[now][x][y]==INF) continue;
          else {
            dp[nxt][x][y]=min(dp[nxt][x][y],dp[now][x][y]);
            dp[nxt][min(x+v[i][0],401)][min(y+v[i][1],401)]=min(dp[nxt][min(x+v[i][0],401)][min(y+v[i][1],401)],dp[now][x][y]+v[i][2]);
            //dp[nxt][min(x+v[i][0],401)][min(y+v[i][1],401)]=min(dp[nxt][min(x+v[i][0],401)][min(y+v[i][1],401)],dp[now][x][y]+v[i][2]);
          }
        }
      }
    //  rep(s,7) {
    //    rep(t,7){
    //      if (dp[nxt][s][t]==INF) cout << "F";
    //      else cout << dp[nxt][s][t];
    //    }
    //    printf("\n"); 
    //  }
    //  printf("\n");
      swap(now,nxt);
    }
    //printf("ok\n");
    int ans=INF;
    rep(i,401){
      rep(j,401){
        if (i==0 || j==0) continue;
        if (mb*i==ma*j) ans=min(ans,dp[now][i][j]);
      }
    }
    if (ans==INF) cout << -1 << endl;
    else cout << ans << endl;
    

    return 0;
  }
