#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> a;
int N;
ll now=2;
ll ans;

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    ll b;
    scanf("%lld", &b);
    a.push_back(b);
  }
  
  ans = a[0] - 1;
  for (int i = 1; i < N; i++)
  {
    if (a[i] == now) {
      now++;
    } else if (a[i] % now == 0) {
      ans = ans + (a[i]/now - 1);
    } else {
      ans += a[i]/now;
    }
  }

  printf("%lld\n", ans);
    
  return 0;
}