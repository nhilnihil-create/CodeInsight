#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int i, W, H, N;

  cin >> W >> H >> N;
  
  int up=H, down=0, right=W, left=0;
  int w, h, a;
  
  rep(i,N){
    cin >> w >> h >> a;
    if(a==1 && left<w) left=w;
    else if(a==2 &&  right>w) right=w;
    else if(a==3 && down<h) down=h;
    else if(a==4 && up>h) up=h;
  }
  
  if(right<left || up < down) cout << 0;
  else cout << (up-down)*(right-left);
}