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
typedef pair<ll, ll> PII;
typedef map<ll, ll> MP;  // MP a;
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
  ll n,k,m,x=0,y=0,z = 0,h=0,w=0,ans=0,sum = 1, Max = -1, Min = 3e9+1;
  string u;
  bool ok=true;
  cin >> n;
  VL a(n);
  map<int, ll> mp;
  rep(i,n){
    cin >> x;
    auto itr = mp.find(x);
    if(itr != mp.end()){
      itr->second++;
    }
    else{
      mp.insert(make_pair(x,1));
    }
  }
  for( auto i = mp.rbegin(); i != mp.rend();i++ ) { 
    if(i->second/2 >= 2 && h > 0 ){
      w = i->first;
    }
    else if(i->second/2 >= 2 && h==0){
      x=i->first;
      pri(x*x);
      return 0;
    } 
    else if(i->second/2 >= 1 && h>0){
      w = i->first;
    }
    else if(i->second/2 >= 1){
      h = i->first;
    }

    if(w>0){
      pri(h*w);
      return 0;
    }
  }
  pri(0);
  return 0;
}