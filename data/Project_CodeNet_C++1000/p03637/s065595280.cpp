#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, l, r) for (int i = (l); i < (r); i++)
#define ALL(x) (x).begin(), (x).end()     //昇順
#define RALL(x) (x).rbegin(), (x).rend()  // 降順
#define pri(x) cout << (x) << "\n"
#define pri2(x, y) cout << (x) << " " << (y) << "\n"
#define pri3(x, y, z) cout << (x) << " " << (y) << " " << (z) << "\n"
const long long mod = 1e9 + 7;
typedef long long ll;
typedef priority_queue<int> PQ;
typedef vector<long long> VL;
typedef vector<bool> VB;
typedef vector<int> VI;  // VI a(n);
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<char> VC;
typedef vector<VS> VSS;
typedef vector<VC> VCC;
typedef vector<VI> VII;  // VII a(n,VI(m)) n * m
typedef vector<VL> VLL;
typedef pair<int, int> PII;
typedef map<int, int> MP;  // MP a;
typedef vector<pair<ll, ll>> PS;

template <class T, class U>
bool chmax(T &a, U b) {
  if (a <= b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T, class U>
bool chmin(T &a, U b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
  os << "{";
  rep(i, (int)v.size()) { os << v[i] << (i < v.size() - 1 ? ", " : ""); }
  os << "}";
  return os;
}

// g++ -std=c++11 prac.cpp
// operator << (cout,a);
// chmin(min,a)
     
int main() {
  ll n, m, k, x=0, y=0 , z = 0, h,w, sum = 0, Max = -1, Min = 3e9+1;
  string u;
  bool ok=true;
  cin >> n;
  VI a(n);
  rep(i,n) {
    cin >> a[i];
    if(a[i]%4==0)
      x++;
    else if (a[i]%2==0)
      y++;
    else
      z++;
  }
  if(x+1 >= z && y==0){
    pri("Yes");
  }
  else if(x >= z){
    pri("Yes");
  }
  else pri("No");

  return 0;
}
