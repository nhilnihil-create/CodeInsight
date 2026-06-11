#include <iostream>
#include <algorithm>
#define mmax 100000
#define nmax 300000
using std::cin;
using std::cout;
struct souv
{
    int l, r;
};
bool shorter(souv a, souv b)
{
    return a.r - a.l < b.r - b.l;
}
int n, m, bit[mmax+1], ans[nmax+1];
souv qr[nmax+1];
void upd(int p, int v)
{
    for(; p; p &= p - 1)
      bit[p] += v;
}
int get(int x)
{
    int sum = 0;
    for(; x <= m; x += x & (-x))
      sum += bit[x];
    return sum;
}
int main()
{
    cin >> n >> m;
    for(int q = 1; q <= n; ++q){
      cin >> qr[q].l >> qr[q].r;
      --qr[q].l;
    }
    std::sort(qr + 1, qr + n + 1, shorter);
    for(int i = 1, j = 1; i <= m; ++i){
      for(; j <= n && qr[j].r - qr[j].l < i; ++j){
        upd(qr[j].r, 1);
        upd(qr[j].l, -1);
      }
      ans[i] = n - j + 1;
      for(int k = i; k <= m; k += i)
        ans[i] += get(k);
    }
    for(int i = 1; i <= m; ++i)
      cout << ans[i] << ' ';
    return 0;
}
