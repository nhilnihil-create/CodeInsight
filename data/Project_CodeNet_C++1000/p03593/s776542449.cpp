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
  ll h, w;std::cin >> h >> w;
  vector<string> s(h);
  vll num(26, 0);
  re(i, h) {
    std::cin >> s[i];
    re(j, w) num[s[i][j] - 'a']++;
  }
  bool flag = true;
  if(h%2==0&&w%2==0) {re(i, 26) if(num[i]%4!=0) flag = false;}
  else if(h%2==1&&w%2==0){
    ll amari = 0, odd=0;
    re(i, 26) {
      if(num[i]%2==1) odd++;
      amari+=num[i]%4;
    }
    if(odd>=2||amari>w) flag = false;
  }else if(h%2==0&&w%2==1){
    ll amari = 0, odd=0;
    re(i, 26) {
      if(num[i]%2==1) odd++;
      amari+=num[i]%4;
    }
    if(odd>=2||amari>h) flag = false;
  }else{
    ll amari = 0, odd=0;
    re(i, 26) {
      if(num[i]%2==1) odd++;
      amari+=num[i]%4;
    }
    if(odd>=2||amari>(h+w-1)) flag = false;
  }
  std::cout << (flag?"Yes":"No") << '\n';
  return 0;
}
