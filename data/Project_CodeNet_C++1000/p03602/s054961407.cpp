#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l4;

#define mp make_pair
#define pb push_back

const int N = 300+1;
int n;
ll d[N][N];

int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      scanf("%lld", &d[i][j]);
  //check
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
	if (k != i && k != j && d[i][k]+d[k][j] < d[i][j])
	  {
	    puts("-1");
	    return 0;
	  }
  //cal
  ll ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = i+1; j <= n; ++j)
      {
	ans += d[i][j];
	for (int k = 1; k <= n; ++k)
	  if (i != k && j != k && d[i][k]+d[k][j] == d[i][j])
	    {
	      ans -= d[i][j];
	      break;
	    }
      }
  printf("%lld\n", ans);
}
