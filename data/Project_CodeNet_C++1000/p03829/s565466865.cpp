#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define bg begin()
#define en end()

using namespace std;

typedef long long ll;

int N, X[100005];
ll ans, A, B;

int main() {
  scanf("%d %lld %lld", &N, &A, &B);
  rep(i, 0, N) scanf("%d", &X[i]);
   
  rep(i, 1, N) ans += min<ll>((X[i]-X[i-1])*A, B);
  
  printf("%lld", ans);
  return 0;

}