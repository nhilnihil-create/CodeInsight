#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n,m;
  cin >> n >> m;
  
  ll a[n+1],b[n+1];
  for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
  
  ll c[m+1],d[m+1];
  for(int i = 1; i <= m; i++) cin >> c[i] >> d[i];
  
  ll ans[n+1] = {0};
  ll dis = 0, mindis = 1e9;
  int check = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      dis = abs(a[i] - c[j]) + abs(b[i] - d[j]);
      if(dis < mindis){
        mindis = dis;
        check = j;
      }//if
    }//for
    ans[i] = check;
    mindis = 1e9;
  }
  
  for(int i = 1; i <= n; i++) cout << ans[i] << endl;;
  
}
