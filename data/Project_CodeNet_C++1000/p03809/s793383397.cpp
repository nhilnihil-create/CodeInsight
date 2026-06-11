#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define TAM 100100

ll A[TAM];
vi G[TAM];

bool ok ( int i, int pi = -1 ) {
  if ( G[i].size() == 1 )
    return true;

  ll sum = 0, maxAj = 0;
  for ( int j : G[i] )
    if ( j != pi ) {
      if ( !ok(j, i) )
        return false;
      sum += A[j];
      maxAj = max ( maxAj, A[j] );
    }

  // x + A[i] = sum
  ll x = sum - A[i];

  if ( x < 0 || maxAj > A[i] )
    return false;

  A[i] -= x;
  return A[i] >= 0;
}

int main() {
  int n;
  scanf ( "%d", &n );
  for ( int i = 1, tmp; i <= n; ++i ) {
    scanf ( "%d", &tmp );
    A[i] = tmp;
  }
  for ( int edges = n-1, a, b; edges--; ) {
    scanf ( "%d%d", &a, &b );
    G[a].pb ( b );
    G[b].pb ( a );
  }

  if ( n == 2 ) {
    puts ( A[1] == A[2] ? "YES" : "NO" );
    return 0;
  }

  int root = 1;
  while ( G[root].size() == 1 ) root++;

  if ( ok(root) && A[root] == 0 ) puts ("YES");
  else puts("NO");
  return 0;
}
