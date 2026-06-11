# include <bits/stdc++.h>
using namespace std;

int ans[1005][1005];
int main(){

  int R, C, h, w;
  cin >> R >> C >> h >> w;
  int d = 1000, sum = 0;
  for(int i=1; i<=R; i++){
    for(int j=1; j<=C; j++){
      if(i%h == 0 && j%w== 0){
        ans[i][j] = -((h*w-1)*d) - 1;
      }
      else ans[i][j] = d;
      sum += ans[i][j];
    }
  }

  if(sum < 0) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  for(int i=1; i<=R; i++){
    for(int j=1; j<=C; j++) cout << ans[i][j] << " ";
    cout << endl;
  }
  return 0;
}