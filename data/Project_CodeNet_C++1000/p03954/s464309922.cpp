#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200001];
int n;
int c(int v, int x){
  return v >= x ? 1 : 0;
}
int bigeq(int x){
  int m = n - 1;
//  cout << m << endl;
  if(a[m] >= x && a[m + 1] >= x
  || a[m] >= x && a[m - 1] >= x)return 1;
  if(a[m] < x && a[m + 1] < x
  || a[m] < x && a[m - 1] < x)return 0;

  int mxall, mxalr;
  mxall = m - 1;
  mxalr = m + 1;
  while(mxall > 0 && c(a[mxall - 1], x) != c(a[mxall], x))mxall--;
  while(mxalr < 2 * n - 2 && c(a[mxalr + 1], x) != c(a[mxalr], x))mxalr++;
  int v = c(a[m], x);
  while(mxall <= m - 1 && mxalr >= m + 1){
    mxall++;
    mxalr--;
    v ^= 1;
  }
  return v;
}
int main(){
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d", &n);
  for(int i = 0;i < 2 * n - 1;i++)
    scanf("%d", a + i);


  int lo = 1, hi = 2*n - 1;
  while(lo < hi){
    int mid = (lo + hi + 1) / 2;
    if(bigeq(mid))
      lo = mid;
    else
      hi = mid - 1;
  }
  cout << lo;
  return 0;
}
