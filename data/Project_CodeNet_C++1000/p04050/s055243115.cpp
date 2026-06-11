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

void err(){
  std::cout << "Impossible" << '\n';
  exit(0);
}
int main(int argc, char const *argv[]) {
  ll n, m;std::cin >> n >> m;
  vll a(m), b;
  ll o = 0;
  for(int i=0;i<m;i++){
    scanf("%lld", &a[i]);
    if(a[i]%2) o++;
  }
  if((n%2&&o>=2)||(n%2==0&&o>2)) err();

  sort(all(a), [](ll x, ll y){ // 奇数を右に
    if(x%2) return false;
    if(y%2) return true;
    return x < y;
  });

  if(m==1&&a[0]==1) b = vll{1};
  else if(m==1) b = vll{1, a[0]-1};
  else{
    if(o==2) swap(a[0], a[m-2]);
    for(int i=0;i<m;i++){
      ll x = 0;
      if(i==0) x = -1;
      if(i==m-1) x = 1;
      if(a[i]+x!=0) b.push_back(a[i]+x);
    }
  }
  re(i, m) std::cout << a[i] << (i==m-1?"\n":" ");
  std::cout << b.size() << '\n';
  re(i, b.size()) std::cout << b[i] << (i==b.size()-1?"\n":" ");
  return 0;
}
