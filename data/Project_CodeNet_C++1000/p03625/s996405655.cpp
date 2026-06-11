#include <iostream>
#include <algorithm>

#define MAXN 100000

typedef long long ll;

using namespace std;

ll A[MAXN];

bool comlarge ( const ll x, const ll y ) { return x > y; }

ll find ( int N )
{
  ll f,s,cnt,i;

  cnt = 0;
  f = A[0];
  for ( i = 0; i < N; ++i  ) {
    if ( f == A[i] ) {
      ++cnt;
      if ( cnt >= 2 ) break;
    } else {
      cnt = 1;
      f = A[i];
    }
  }

  s = A[++i];
  cnt = 0;
  for ( ; i < N; ++i ) {
    if ( s == A[i] ) {
      ++cnt;
      if ( cnt >= 2 ) {
        return f*s;
      }
    } else {
      cnt = 1;
      s = A[i];
    }
  }

  return 0;
}


int main()
{
  int N;

  cin >> N;

  for ( int i = 0; i < N; ++i ) scanf("%d", &A[i]);
  sort(A,A+N,comlarge);

  cout << find(N) <<"\n";
}
