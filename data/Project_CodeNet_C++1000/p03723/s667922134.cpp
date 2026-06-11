#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const ll INF = 2e15;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(){
  ll a, b, c;
  cin >> a >> b >> c;
  ll count = 0;
  if(a%2==1||b%2==1||c%2==1){
      print(count);
      return 0;
  }
  if (a == b&&b == c){
    print(-1);
    return 0;
  }
  while (1){
    ll A = a;
    ll B = b;
    ll C = c;
    a = B / 2 + C / 2;
    b = A / 2 + C / 2;
    c = A / 2 + B / 2;
    count++;
    if(a%2==1||b%2==1||c%2==1){
      print(count);
      return 0;
    }
  }
}