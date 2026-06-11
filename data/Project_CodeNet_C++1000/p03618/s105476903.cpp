#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())
#define PB push_back
#define MP make_pair
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define sqr(x)  ((x) * (x)) 
#define cub(x)  ((x) * (x) * (x))
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main() {
  string a; cin >> a;
  map<char,ll> m;
  FOR(i,0,a.length()-1){
    ++m[a[i]];
  }

  ll ans = 1;
  ans += a.length() * (a.length()-1) / 2;
  FOR(i,0,25){
    ans -= m[char('a' + i)] * (m[char('a' + i)] - 1) / 2;
  }

  cout << ans << endl;


}

