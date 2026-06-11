# include <bits/stdc++.h>
using namespace std;

int main(){

  int balls[100005], containsRed[100005];
  int n, m;
  cin >> n >> m;

  for(int i=1; i<=n; i++){
    balls[i] = 1;
    containsRed[i] = (i==1);
  }

  for(int i=1; i<=m; i++){
    int x, y;
    cin >> x >> y;
    if(containsRed[x]) containsRed[y] = true;
    balls[x]--;
    balls[y]++;
    if(balls[x] == 0){
      containsRed[x] = false;
    }
  }

  int ans = 0;
  for(int i=1; i<=n; i++) ans += containsRed[i];
  cout << ans << endl;
  return 0;
}