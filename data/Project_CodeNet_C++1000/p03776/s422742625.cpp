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
#include <iomanip>

void comb(vector<vector <long long int> > &v){
  for(int i = 0;i <v.size(); i++){
    v[i][0]=1;
    v[i][i]=1;
  }
  for(int k = 1;k <v.size();k++){
    for(int j = 1;j<k;j++){
      v[k][j]=(v[k-1][j-1]+v[k-1][j]);
    }
  }
}
int main(int argc, char const *argv[]) {
  ll s=0, n, a, b;std::cin >> n >> a >> b;
  vll v(n), x;
  vector<vector<long long int> > V(51,vector<long long int>(51,0));
  comb(V);
  multiset<ll> z, y;
  re(i, n) {
    std::cin >> v[i];
    z.insert(v[i]);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  re(i, b){
    if(i<a) s+=v[i];
    if(i>=a&&v[i]<v[a-1]) break;
    x.push_back(v[i]);
    y.insert(v[i]);
  }
  std::cout << fixed << setprecision(10) << (ld)((ld)s/(ld)a) << '\n';
  ll ans = 0;
  if(y.count(*y.begin())==x.size()){
    for(int i=a;i<=min(b, (ll)z.count(*y.begin()));i++){
      ans+=V[z.count(*y.begin())][i];
    }
  }else{
    ans = V[z.count(*y.begin())][a-(x.size() - y.count(*y.begin()))];
  }
  std::cout << ans << '\n';
  return 0;
}
