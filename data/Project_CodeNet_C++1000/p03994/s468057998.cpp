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

ll cost(char a){
  if(a-'a'==0) return 0;
  return 26 - (a - 'a');
}
int main(int argc, char const *argv[]) {
  string s;std::cin >> s;ll n = s.size();
  ll k;std::cin >> k;
  re(i, n){
    if(cost(s[i])<=k) k-=cost(s[i]), s[i] = 'a';
    if(i==n-1){
      ll t = s[i] - 'a';
      re(j, k) t++;
      s[i] = (t%26) +'a'; 
    }
  }
  std::cout << s << '\n';
  return 0;
}
