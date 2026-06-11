      #include <iostream>
      #include <string>
      #include <vector>
      #include <algorithm>
      #include <set>
      using namespace std;
      typedef long long ll;
      #define rep(i,n) for (int i=0;i < (int)(n);i++)
      ll INF = 1LL  << 60;

      ll d[201][201];

      int main(){
        int n,m,r;
        cin >> n >> m >> r;
        vector<int> per(r);
        rep(i,r) cin >> per[i];
        rep(i,n) rep(j,n) { 
          if (i == j) d[i][j] = 0;
          else d[i][j] = INF;
         }
        rep(i,m){
          int x,y,c;
          cin >> x >> y >> c;
          x--;y--;
          d[x][y] = c;
          d[y][x] = c;
        }
        for (int i = 0;i < n;i++){
          for (int j = 0;j < n;j++){
            for (int k = 0;k < n;k++){
              d[j][k] = min(d[j][k],d[j][i]+d[i][k]);
            }
          }
        }
        //cout << endl;
        sort(per.begin(),per.end());
        ll ans = INF;
        do{
          //rep(i,r){
          //  cout << per[i] << " ";
          //}
          //cout << endl;
          ll cnt = 0;
          for (int i=0;i < r-1;i++){
            cnt+=d[per[i]-1][per[i+1]-1];
          }
          ans = min(ans,cnt);

        }while(next_permutation(per.begin(),per.end()));
        
        cout << ans << endl;
        
        return 0;

        
      }
        
        