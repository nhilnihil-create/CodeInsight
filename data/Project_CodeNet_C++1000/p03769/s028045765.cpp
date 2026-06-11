#include <bits/stdc++.h>
using namespace std;

long long n;
int a[1010], cnt;

int main(void) {
  scanf("%lld", &n);
  deque<int> q;
  int m = 0;
  n++;
  while((1LL << m) <= n) m++;
  m -= 2;
  while(~m) {
    q.push_back(++cnt);
    if(n >> m & 1) q.push_front(++cnt);
    m--;
  }
  int now = 0;
  while(!q.empty()) {
    a[++now] = q.front(); q.pop_front();
  }
  cout << now * 2 << endl;
  for(int i = 1; i <= now; i++)
    a[now + i] = i;
  for(int i = 1; i <= now * 2; i++)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
