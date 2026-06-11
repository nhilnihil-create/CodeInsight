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
    
template<typename T>
T gcd(T a, T b){
	return b != 0 ? gcd(b, a % b) : a;
}    

template<typename T>
T lcm(T a, T b){
    return a/gcd(a,b)*b;
}    


int main() {
  ll n,k,m,x=0, y=0 , z = 0, h,w, ans=0,sum = 1, Max = -1, Min = 3e9+1;
  string u;
  bool ok=true;
  cin >> n;
  VL a(n); rep(i,n) cin >> a[i];
  sort(ALL(a));
  if(n==1){
    pri(a[0]);
    return 0;
  }
  else{
    x = lcm(a[0],a[1]);
    for(int i=2; i<n; i++){
      x = lcm(a[i],x);
    }
    pri(x);
    return 0;
  }
}