#include <bits/stdc++.h>
using namespace std;

int h, w;
long long ans[10] = {};
map<int, map<int, bool> > mp;

int nineSearch(int x, int y){
  int ans = 0;
  for(int p = -1;p < 2;p++){
    for(int q = -1;q < 2;q++){
      if(x+p < 0 || x+p >= w || y+q < 0 || y+q >= h) return 10;
      if(mp[x+p][y+q]) ans++;
    }
  }

  return ans;
}

int main(){
  int n;
  cin >> h >> w >> n;
  ans[0] = (long long)(h-2) * (long long)(w-2);

  int x, y;
  for(int i = 0;i < n;i++){
    cin >> y >> x;
    y--; x--;
    for(int p = -1;p < 2;p++){
      for(int q = -1;q < 2;q++){
        int tmp = nineSearch(x+p,y+q);
        if(tmp < 9){
          ans[tmp]--;
          ans[tmp+1]++;
        }
      }
    }
    mp[x][y] = true;
  }

  for(int i = 0;i < 10;i++){
    cout << ans[i] << endl;
  }
  return 0;
}

