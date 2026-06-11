#include <iostream>
#include <vector>

using namespace std;

#define repd(i,a,b) for (int i=(a);i<(b);++i)
#define rep(i,n) repd(i,0,n)
typedef long long ll;

int main(){
  ll q, h, s, d;
  ll n;
  cin >> q >> h >> s >> d;
  cin >> n;
  h = min(q*2, h);
  s = min(h*2, s);
  d = min(s*2, d);
  cout << (n/2) * d + (n%2) * s << endl;
  return 0;
}
