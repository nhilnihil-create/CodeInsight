#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long int;

int main() {
  ll W, H, N;
  cin >> W >> H >> N;

  ll min_x = 0, max_x = W;
  ll min_y = 0, max_y = H;
  for (ll i = 0; i < N; i++)
  {
    ll x, y, a;
    cin >> x >> y >> a;

    switch (a)
    {
    case 1:
      min_x = max(min_x, x);
      break;
    case 2:
      max_x = min(max_x, x);
      break;
    case 3:
      min_y = max(min_y, y);
      break;
    case 4:
      max_y = min(max_y, y);
      break;
    
    default:
      break;
    }
  }
  cout << max(max_x - min_x, 0LL) * max(max_y - min_y, 0LL) << endl;
}