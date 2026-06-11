#include <iostream>
#include <algorithm>
#define nmax 100000
using namespace std;
int n, a[nmax+1], cdd[nmax+1][2];
long long ans[nmax+1];
void in()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
}
void prs()
{
    int cnt = 1, mx = a[1];
    cdd[0][1] = 0;
    cdd[1][0] = 1;
    cdd[1][1] = a[1];
    for(int i = 2; i <= n; ++i) if(a[i] > mx){
      mx = a[i];
      cdd[++cnt][0] = i;
      cdd[cnt][1] = a[i];
    }
    std::sort(a + 1, a + n + 1);
    int ci = n, cm = a[n];
    for(int u = cnt; u > 0; --u){
      int i = cdd[u][0], v = cdd[u - 1][1];
      ans[i] = (long long) (n - ci) * (cm - v);
      for(; ci > 0 && a[ci] >= v; --ci)
        ans[i] += a[ci] - v;
      cm = v;
    }
}
void out()
{
    for(int i = 1; i <= n; ++i)
      cout << ans[i] << '\n';
}
void run()
{
    in();
    prs();
    out();
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}
