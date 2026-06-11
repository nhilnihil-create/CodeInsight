#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1000000007;
const int BASE = 27;
const int oo = 1e9;
const double EPS = 1e-9;
const int MX = 1e5+1;

ll f(ll a , ll b){
  if(a>b)swap(a,b);
  if(a == 0)return -b;
  ll rm = b/a;
  return 2*a*rm+f(a,b%a);
}

ll n , x;

int main() {
  cin >> n >> x;
  cout << (n+f(x,n-x)) << endl;
  return 0;
}
