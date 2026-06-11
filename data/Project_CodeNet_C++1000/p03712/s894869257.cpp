#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int h,w;
  cin >> h >> w;
  
  string s[h+2][w+2];
  rep(i,h+2){
    rep(j,w+2){
      if(i == 0 || i == h+1){
        s[i][j] = '#';
      }else if(j == 0 || j == w+1){
        s[i][j] = '#';
      }else{
        cin >> s[i][j];
        j += w-1;
      }
    }
  }
    
  rep(i,h+2){
    rep(j,w+2){
      cout << s[i][j];
    }
    cout << endl;
  }
    
}