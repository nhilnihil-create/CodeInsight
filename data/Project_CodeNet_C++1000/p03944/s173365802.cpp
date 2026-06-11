#include <bits/stdc++.h>
using namespace std;

int main() {
  int w, h, n;
  cin >> w >> h >> n;
  int w1, w2, h1, h2;
  w1=0; w2=w; h1=0; h2=h;
  for (int i=0; i<n; i++){
    int x, y, a;
    cin >> x >> y >> a; 
    if (a==1)
      w1 = max(x,w1);
    if (a==2)
      w2 = min(x,w2);
    if (a==3)
      h1 = max(y,h1);
    if (a==4)
      h2 = min(y,h2);
  }
  int width = max(w2-w1,0);
  int height = max(h2-h1,0);
  cout << width * height << endl;
}