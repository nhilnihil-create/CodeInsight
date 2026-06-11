#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
using P = pair<int, int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef vector<ll> vi;
const int MOD = 1000000007;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
  ll x, a, b;
  cin >> x >> a >> b;
  ll y, z;
  if(x>=a){
    y = x - a;
  }
  else{
    y = a - x;
  }
  if(x>=b){
    z = x - b;
  }
  else{
    z = b - x;
  }
  if(y>z){
    print('B');
  }
  else{
    print('A');
  }
}