#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvvl vector<vvl>
#define vvl vector<vector<ll>>
#define VV(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define VVV(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  ll h, w, d;std::cin >> h >> w >> d;
  ll N = max(h, w) * 2;
  vvl dat = VV(N, N, 0, ll);
  vvl ans = VV(h, w, -1, ll);
  map<ll, char> c;
  c.emplace(0, 'R');
  c.emplace(1, 'G');
  c.emplace(2, 'Y');
  c.emplace(3, 'B');
  for(ll i=0;i<N;i++){
    for(ll j=0;j<N;j++){
      if((i/d)%2==0) dat[i][j] = ((j/d)%2==0?0:1);
      else dat[i][j] = ((j/d)%2==0?2:3);
    }
  }
  /*
  re(i, N){
    re(j, N) std::cout << dat[i][j];
    std::cout << '\n';
  }
  */
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      ans[i][j] = dat[i-j+N/2][i+j];
    }
  }

  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++) std::cout << c.at(ans[i][j]);
    std::cout << '\n';
  }
  return 0;
}
