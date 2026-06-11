#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

int main(void){
  ll h, w;
  cin >> h >> w;
  
  ll m = INF;
  for (int i = 1; i < w; i++){
    ll s1  = h * i;
    ll r = max(s1, (h + 1)/2 * (w - i)) - min(s1, h / 2 * (w - i));
    m = min(r, m);
  }
  for (int i = 1; i < w; i++){
    ll r;
    ll s1  = h * i;
    r = max(s1, (w - i + 1)/2 * h) - min(s1, (w - i) / 2 * h);
    m = min(r, m);
  }
  for (int i = 1; i < h; i++){
    ll r;
    ll s1  = w * i;
    r = max(s1, (w + 1)/2 * (h - i)) - min(s1, w / 2 * (h - i));
    m = min(r, m);
  }
  for (int i = 1; i < h; i++){
    ll r;
    ll s1  = w * i;
    r = max(s1, (h - i + 1)/2 * w) - min(s1, (h - i) / 2 * w);
    m = min(r, m);
  }

  cout << m << endl;






  return 0;
}
