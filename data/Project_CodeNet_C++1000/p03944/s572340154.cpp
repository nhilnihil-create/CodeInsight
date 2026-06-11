#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std; //std::の省略のため
using ll = long long;

int main()
{
  int w, h, n;
  cin >> w >> h >> n;

  int x[n], y[n], a[n];

  for(int i = 0; i < n; i++){
    cin >> x[i] >> y[i] >> a[i];
  }

  int s[w][h];

  for(int j = 0; j < w; j++){
      for(int k = 0; k < h; k++)
        s[j][k] = 0;
  }

  for(int i = 0; i < n; i++){
    if(a[i] == 1){
      for(int j = 0; j < x[i]; j++){
        for(int k = 0; k < h; k++)
          s[j][k] = 1;
      }
    }
    else if(a[i] == 2){
      for(int j = x[i]; j < w; j++){
        for(int k = 0; k < h; k++)
          s[j][k] = 1;
      }
    }
    else if(a[i] == 3){
      for(int j = 0; j < w; j++){
        for(int k = 0; k < y[i]; k++)
          s[j][k] = 1;
      }
    }
    else if(a[i] == 4){
      for(int j = 0; j < w; j++){
        for(int k = y[i]; k < h; k++)
          s[j][k] = 1;
      }
    }
  }

  ll ans = 0;

  for(int j = 0; j < w; j++){
      for(int k = 0; k < h; k++)
        if(s[j][k] == 0) ans++;
  }

  cout << ans << endl;

}
