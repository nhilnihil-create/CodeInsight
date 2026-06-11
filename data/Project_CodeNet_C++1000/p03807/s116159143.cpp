#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using st = string;
using db = double;
using vll = vector<long long>;
using vvll = vector<vll>;
using vst = vector<st>;
using vchar = vector<char>;
#define rep(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define vrep(i, vec) for(auto& i : vec)
#define vin(vec) for(auto& i : vec) cin >> i
#define all(v) v.begin(), v.end()
ll mod = 1000000007;

bool travel(ll dt, ll dx, ll dy){
  if(dt >= dx + dy)if((dt - dx - dy) % 2 == 0) return true;
  return false;
}

int main(){
  ll n;
  cin >> n;
  vll a(n);
  vin(a);
  ll odd = 0;
  vrep(i, a) if(i % 2 == 1) odd++;
  cout << (odd % 2 == 0 ? "YES" : "NO") << endl;
}