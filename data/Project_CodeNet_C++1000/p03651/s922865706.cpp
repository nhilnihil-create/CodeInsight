

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a%b);}

int v[100005];

int main(void) {
  int n, k;
  cin >> n >> k;
  rep(i, 0, n) scanf("%d", &v[i]);
  int t = v[0], mx = v[0];
  rep(i, 1, n) {
    t = gcd(t, v[i]);
    mx = max(mx, v[i]);
  }
  
  if (k<=mx && k%t==0) puts("POSSIBLE");
  else puts("IMPOSSIBLE");
  
  
    return 0;
}

