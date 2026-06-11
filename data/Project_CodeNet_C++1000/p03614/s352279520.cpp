#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l4;

#define mp make_pair
#define pb push_back


const int maxn = 1e5+1;
int n, a[maxn];


int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", a+i);
  int i = 1;
  int ans = 0;
  while (i <= n)
    {
      while (i <= n && a[i] != i)
	++i;
      if (i > n)
	break;

      int old = i;
      while (i <= n && a[i] == i)
	++i;
      ans += (i-old+1)/2;
    }
  printf("%d\n", ans);
}
