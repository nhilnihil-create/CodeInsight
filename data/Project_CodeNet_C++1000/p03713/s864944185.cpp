#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long h, w;
  cin >> h >> w;
  long long res = h*w, a, b, c;
  for(int i = 1; i < h; i++){
    a = i*w;
    b = (h-i)*(w/2);
    c = (h-i)*(w-w/2);
    res = min(max({a, b, c}) - min({a, b, c}), res);
    b = ((h-i)/2)*w;
    c = ((h-i)-(h-i)/2)*w;
    res = min(max({a, b, c}) - min({a, b, c}), res);
  }
  for(int j = 1; j < w; j++){
    a = h*j;
    b = (w-j)*(h/2);
    c = (w-j)*(h-h/2);
    res = min(max({a, b, c}) - min({a, b, c}), res);
    b = ((w-j)/2)*h;
    c = ((w-j)-(w-j)/2)*h;
    res = min(max({a, b, c}) - min({a, b, c}), res);
  }
  cout << res << endl;
  return 0;
}