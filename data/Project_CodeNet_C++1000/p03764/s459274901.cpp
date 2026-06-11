#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
using ll = long long int;
const lint INF = 1001001001001001LL;
const lint MOD = 1000000007LL;
int di[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dj[] = {0, 1, 0, -1, 1, 1, -1, -1};

void yes(){ cout << "yes" << endl; }
void Yes(){ cout << "Yes" << endl; }
void YES(){ cout << "YES" << endl; }
void no(){ cout << "no" << endl; }
void No(){ cout << "No" << endl; }
void NO(){ cout << "NO" << endl; }
void possible(){ cout << "possible" << endl; }
void Possible(){ cout << "Possible" << endl; }
void POSSIBLE(){ cout << "POSSIBLE" << endl; }
void impossible(){ cout << "impossible" << endl; }
void Impossible(){ cout << "Impossible" << endl; }
void IMPOSSIBLE(){ cout << "IMPOSSIBLE" << endl; }

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for(int i = s; i < t; i++)
#define all(a) a.begin(),a.end()

int main(){
  
  lint n, m; cin >> n >> m;
  vector<lint> x(n);
  vector<lint> y(m);
  rep(i, n) cin >> x[i];
  rep(i, m) cin >> y[i];
  
  sort(all(x));
  sort(all(y));

  lint ansx = 0;
  lint ansy = 0;

  rep(i, n){
    ansx += x[i] * i;
    ansx -= x[i] * (n - i - 1);
    ansx = (ansx + MOD) % MOD;
  }

  rep(i, m){
    ansy += y[i] * i;
    ansy -= y[i] * (m - i - 1);
    ansy = (ansy + MOD) % MOD;
  }
  
  cout << ansx * ansy % MOD << endl;

  return 0;
}
