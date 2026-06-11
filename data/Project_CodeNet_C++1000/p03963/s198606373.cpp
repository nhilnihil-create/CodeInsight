#include <bits/stdc++.h>
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)

typedef unsigned long long ull;
typedef long long ll;

const int INF = 1001001001;
const ll MOD = 1e9 + 7;

using namespace std;
using P = pair<int,int>;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }

bool is_prime(ll n) {
  if (n == 2) return true;
  REP(i, 2, n) {
      if (n%i == 0)
      {
        /* code */
        return false;
      }
  }
  return true;
}


int main() {
  ull n, k;
  cin >> n >> k;

  ull fact = 1;
  if (n == 1) 
  {
      fact = k;
      cout << fact << endl;
      return 0;
  }
  for (ull i = n; i > 0; i--)
  {
      fact *= (i == n) ? k : k-1;
  }
  
  cout << fact << endl;
  return 0;
}