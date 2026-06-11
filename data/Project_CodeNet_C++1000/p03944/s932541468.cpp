#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int W, H, n;
  cin >> W >> H >> n;
  vector<set<int>> a(4);
  a[0].insert(0);
  a[1].insert(W);
  a[2].insert(0);
  a[3].insert(H);
  rep(i,n) {
    int x, y, A;
    cin >> x >> y >> A;
    A--;
    if(A<=1) a[A].insert(x);
    else a[A].insert(y);
  }
  int w=*begin(a[1])-*rbegin(a[0]);
  int h=*begin(a[3])-*rbegin(a[2]);
  if(w<0||h<0) w=0;

  cout << w*h << endl;
}