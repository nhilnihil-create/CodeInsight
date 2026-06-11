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
  
  string s; cin >> s;
  string t; cin >> t;
  lint n = s.size();
  lint m = t.size();
  vector<lint> cnt1(n + 1, 0);
  vector<lint> cnt2(m + 1, 0);
  rep(i, n){
    if(s[i] == 'A') cnt1[i + 1] = 1;
    else cnt1[i + 1] = 2;
    cnt1[i + 1] += cnt1[i];
  }

  rep(i, m){
    if(t[i] == 'A') cnt2[i + 1] = 1;
    else cnt2[i + 1] = 2;
    cnt2[i + 1] += cnt2[i];
  }


  lint q; cin >> q;
  rep(i, q){
    lint a, b, c, d; cin >> a >> b >> c >> d;
    lint val1 = cnt1[b] - cnt1[a - 1];
    lint val2 = cnt2[d] - cnt2[c - 1];
    if((lint)abs(val1 - val2) % 3 == 0) YES();
    else NO();
  }
  return 0;
}
