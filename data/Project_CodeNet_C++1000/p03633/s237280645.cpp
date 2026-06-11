#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll INF = (1LL << 60);
ll gcd(ll a, ll b){
    if(b == 0)return a;
    return gcd(b,a%b);
}

ll lcm(ll c, ll d){
    ll g = gcd(c,d);
    ll l = c/g*d;//最小公倍数
    return l;
}
int main() {
  int n;
  cin >> n;
  ll res = 1;
  rep(i,n) {
    ll a;
    cin >> a;
    res = lcm(res, a);
  }
  cout << res << endl;
  return 0; 
} 