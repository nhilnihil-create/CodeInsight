#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  
  // Represents the linear function as kx + b
  vector<long long> dk(m * 2), db(m * 2); 
  for (int i = 0; i < n - 1; i++) {
    int s = a[i] - 1, t = a[i + 1] - 1;
    if (s > t) t += m;
    
    dk[s + 1]--;
    dk[t + 1]++;
    db[s + 1] += s + 1;
    db[t + 1] -= s + 1;
  }

  long long y = 0;
  for (int i = 0; i < n - 1; i++)
    if (a[i] < a[i + 1])
      y += a[i + 1] - a[i];
    else
      y += a[i + 1] - a[i] + m;

  vector<long long> dy(m);
  long long k = 0, b = 0;
  for (int i = 0; i < m * 2; i++) {
    k += dk[i];
    b += db[i];

    dy[i % m] += k * i + b;
  }

  long long ans = y;
  for (int i = 0; i < m; i++)
    ans = min(ans, y + dy[i]);
  printf("%lld\n", ans);

  return 0;
}