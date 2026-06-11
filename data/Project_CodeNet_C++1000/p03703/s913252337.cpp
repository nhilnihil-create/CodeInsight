#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <set>
#include <cstdio>
#include <vector>
#include <iostream>
#include <utility>
#include <queue>
#include <map>

#define fir first
#define sec second
#define sz(s) (s).size()
#define pb push_back
#define Get(n) scanf("%d",&n);
#define gets(s) string s;cin >> (s);
#define prfi(n) printf("%d", &n);
#define prfd(n) printf("%lf", &n);
#define All(s) (s).begin(), (s).end()
#define rep(i,j) for(int (i)=0;(i)<(j);(i)++)
#define For(i,j,k) for(int (i)=(j);(i)<(k);(i)++)
#define repd(i,j) for(int (i)=(j);(i)>=0;(i)--)
#define Ford(i,j,k) for(int (i)=(j);i>=(k);i--)
#define vfor(c,v) for(auto (c): v)
#define dump(x)  std::cout << #x << " = " << (x) << std::endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

using ll = long long;
using pii = std::pair<int,int>;
using vi = std::vector<int> ;
using vvi = std::vector<vi> ;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vd = std::vector<double> ;
using vvd = std::vector<vd> ;
using qi = std::queue<int> ;
using vpii = std::vector<std::pair<int, int> >;
using namespace std;

const int Mod = (1e9) + 7;
const int max_n = 3 * (1e5) + 1;
const int max_m = 83 * (1e5) + 1;
const int INF = 10241024;
const ll INFL = (1ll << 62) - 1;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
//_____________________________________Templates_________________________________________//

template<class T1, class T2> inline void chmin(T1 &a, T2 b){if(a > b) a = b;}
template<class T1, class T2> inline void chmax(T1 &a, T2 b){if(a < b) a = b;}

//mainly use for dynamic prog
template<class T1, class T2>
void update(T1 &a, T2 b){
  a += b;
  if(a > Mod) a %= Mod;
}

inline void IN(void){
  return;
}

template <typename First, typename... Rest>
void IN(First& first, Rest&... rest){
  cin >> first;
  IN(rest...);
  return;
}

inline void OUT(void){
  cout << "\n";
  return;
}

template <typename First, typename... Rest>
void OUT(First first, Rest... rest){
  cout << first << " ";
  OUT(rest...);
  return;
}

struct BIT{
  vi bit;
  int n;

  BIT(int n) : n(n){
    bit.resize(n+1);
  }

  void init(int N){
    bit.resize(N+1);
  }

  int sum (int i){
    int s = 0;
    while(i > 0){
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }

  void add(int i, int x){
    while(i <= n){
      bit[i] += x;
      i += i & -i;
    }
  }

  int get(int r, int l){
    return sum(r) - sum(l-1);
  }

};
//_____________________　following sorce code_________________________//
int n,m,k;
//vvll dp(400, vll(400));
string S;
vll cost(1 << 16);
int a;
int h,w;
vvi v;
vll u;
vll b;
bool check(){

}

int main () {
  cin.tie(0);
  ios::sync_with_stdio(false);
  IN(n,k);
  u = b = vll(n+1);
  rep(i,n){
    IN(u[i]);
  }
  rep(i,n){
    b[i+1] += b[i] + u[i] - k;
  }
  //for(auto c : b)OUT(c);
  vll v = b;
  sort(All(v));
  v.erase(unique(All(v)), v.end());
  ll ans = 0;
  BIT bit(n+1);
  rep(i,n+1){
    int pos = lower_bound(All(v), b[i]) - v.begin();
    pos++;
    ans += bit.sum(pos);
    bit.add(pos, 1);
  }
  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}