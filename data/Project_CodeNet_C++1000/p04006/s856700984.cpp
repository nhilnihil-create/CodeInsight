#include <bits/stdc++.h>
using namespace std;
 
// 0-indexed
// now node k
// child node k*2+1 and k*2+2
// parent node (k-1)/2
struct data {
  int a;
};
const int maxint = 2147483647;
data resetdata = {maxint};
struct RMQ {
  // except bottom size
  int sizen;
  vector<data> dat;
  RMQ(int newn = 1, data resets = resetdata) {
    reset(newn, resets);
  }
  void reset(int newn = 1, data resets = resetdata) {
    sizen = 1;
    while(sizen < newn) sizen *= 2;
    dat.resize(2 * sizen - 1);
    for(int i = 0; i < dat.size(); ++i) dat[i] = resets;
  }
  // "go up" process
  // data[k].a = newnum
  bool update(int k, int newnum) {
    k += sizen - 1;
    dat[k].a = newnum;
    while(k > 0) {
      k = (k - 1) / 2;
      dat[k].a = min(dat[k * 2 + 1].a, dat[k * 2 + 2].a);
    }
    return 1;
  }
  // "go down" process
  // return min number in [a,b)
  // pick(a,b,0,0,sizen)
  int pick(int a, int b, int k = 0, int l = 0, int r = -1) {
    if(r == -1) r = sizen;
    // [l,r)[a,b) or [a,b)[l,r)
    if(r <= a || b <= l) return maxint;
    // [a,[l,r),b)
    if(a <= l && r <= b) return dat[k].a;
    // else
    int nowl, nowr, nextlr = k * 2 + 1, med = (l + r) / 2;
    nowl = pick(a, b, nextlr, l, med);
    nowr = pick(a, b, nextlr + 1, med, r);
    return min(nowl, nowr);
  }
};
RMQ rmq;
long long n, ans = 100000000000000000, x;
long long a[20005] = {0};
 
int main() {
  cin >> n >> x;
  rmq = RMQ(2 * n + 1);
  for(long long i = 0; i < n; ++i) {
    cin >> a[i];
    rmq.update(i, a[i]);
    rmq.update(i + n, a[i]);
  }
  for(long long i = 0; i < n; ++i) {
    long long nans = i * x;
    for(long long j = 0; j < n; ++j)
      nans += rmq.pick(j + n - i, j + n + 1);
    ans = min(ans, nans);
  }
  cout << ans << endl;
  return 0;
}