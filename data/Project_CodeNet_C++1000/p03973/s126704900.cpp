#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vll vector<ll>
#define rep(c, a, b) for(ll c=a;c<b;c++)
#define re(c, b) for(ll c=0;c<b;c++)
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  ll p, n;std::cin >> n;
  deque<ll> h;
  re(i, n){
    std::cin >> p;
    h.push_back(p);
  }
  ll c = 0, now = 0;
  while(!h.empty()){
    if(h.front()<=now+1) {
      if(h.front()==now+1) now++;
      h.pop_front();
    }else{
      if(h.front()<=2*(now+1)){
        h.front()=1, c++;
      }else{
        c+=2*(h.front()/(2*(now+1))), h.front()%=(2*(now+1));
        if(h.front()<=(now+1)) c--, h.front()+=now+1;
        if(h.front()<=(now+1)) c--, h.front()+=now+1;
      }
    }
  }
  std::cout << c << '\n';
  return 0;
}
