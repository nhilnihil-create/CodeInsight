#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;

int main() {
  int W, H, N;
  cin >> W >> H >> N;
  int mx=W, Mx=0, my=H, My=0;
  int x, y, a;
  for (int i=0; i<N; i++) {
    cin >> x >> y >> a;
    if (a==1) {Mx=max(Mx, x);}
    if (a==2) {mx=min(mx, x);}
    if (a==3) {My=max(My, y);}
    if (a==4) {my=min(my, y);}
  }
  cout << max(0, mx-Mx)*max(0, my-My) << endl;
}