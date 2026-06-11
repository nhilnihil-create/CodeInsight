#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i, m, n) for(int i = m; i < n; i++)
#define INF INT_MAX
#define MOD 1000000007
#define fcout cout << fixed << setprecision(15)
typedef long long ll;
typedef pair<int, int> P;
int gcd(int a,int b){return b?gcd(b,a%b):a;};
int lcm(int a,int b){return a * b / gcd(a, b);};
int mod(int a,int b){return (a+b-1)/b;};
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){std::fill( (T*)array, (T*)(array+N), val );};
template<class T>inline bool chmax(T& a,T b){if(a < b){a=b;return true;}return false;};
template<class T>inline bool chmin(T& a,T b){if(a > b){a=b;return true;}return false;};



int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  int p[n];
  rep(i, n) {
    cin >> p[i];
    p[i]--;
  }
  int res = 0;
  rep(i, n - 1) {
    if(p[i] == i) {
      swap(p[i], p[i + 1]);
      res++;
    }
  }
  if(p[n - 1] == n - 1) res++;

  cout << res << endl;
  return 0;
}
