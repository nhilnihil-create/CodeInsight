// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

typedef pair<int, int> P;
int main() {
  int h, w, n; cin >> h >> w >> n;
  int G[101][101];
  vector<P> A;
  loop(i,0,n) {
    int a;
    cin >> a;
    loop(j,0,a) A.emplace_back(a, i+1);
  }
  sort(A.rbegin(), A.rend());
  int idx = 0;
  loop(y,0,h) {
    int init,end,step;
    if (y%2==0) init = 0,end=w,step=1;
    else init=w-1,end=-1,step=-1;
    for (int x = init; x != end; x += step) {
      G[y][x] = A[idx++].second;
    }
  }
  
  loop(y,0,h) {
    loop(x,0,w) {
      if (x != 0) cout << " ";
      cout << G[y][x];
    }
    cout << endl;
  }
  
  return 0;
}
