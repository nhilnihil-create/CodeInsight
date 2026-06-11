#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m,p = 0;
  cin >> n >> m;
  vector<int>data(n,1);
  vector<bool>red(n,false);
  red[0] = true;
  for(int i = 0;i < m;i++){
    int x,y;
    cin >> x >> y;
    x--;y--;
    data[x]--;
    data[y]++;
    if(red[x]) red[y] = true;
    if(data[x] == 0) red[x] = false;
  }
  int ans = 0;
  for(int i = 0;i < n;i++){
    if(data[i] > 0 && red[i]) ans++;
  }
  cout << ans << endl;
}
