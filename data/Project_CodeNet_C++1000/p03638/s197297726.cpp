#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;


int main(){
  int h, w;
  int n;
  cin >> h >> w >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int x = 0, y = 0;
  bool rev = false;
  vector<vector<int>> ans(h, vector<int>(w));
  rep(i, n){
    int cur = a[i];
    while(cur > 0){
      ans[x][y] = i + 1;
      cur--;
      if(rev){
        if(x - 1 < 0){
          y++;
          rev = !rev;
        } else {
          x--;
        }
      } else {
        if(x + 1 >= h){
          y++;
          rev = !rev;
        } else {
          x++;
        }
      }
    }
  }
  
  rep(i, h){
    rep(j, w){
      cout << ans[i][j] << ' ';
    }
    cout << endl;
  }
}
