#include <bits/stdc++.h>
using namespace std;

// 0-indexed
// now node k
// child node k*2+1 and k*2+2
// parent node (k-1)/2
struct data {
  pair<long long, long> a;
};
const pair<long long, long long> minint = make_pair(0, 0);
const pair<long long, long> maxint =
    make_pair(1000000000000000000, 0);
data resetdata1 = {maxint};
data resetdata2 = {minint};
struct RMQ {
  // except bottom size
  int sizen;
  vector<data> dat;
  RMQ(bool ch = 1, int newn = 1, data resets = resetdata1) {
    reset(ch, newn, resets);
  }
  void reset(bool ch, int newn = 1,
             data resets = resetdata1) {
    sizen = 1;
    while(sizen < newn) sizen *= 2;
    dat.resize(2 * sizen - 1);
    if(ch)
      for(int i = 0; i < dat.size(); ++i)
        dat[i] = resetdata2;
    else
      for(int i = 0; i < dat.size(); ++i) dat[i] = resets;
  }
  // "go up" process
  // data[k].a = newnum
  bool update1(int k, pair<long long, long long> newnum) {
    k += sizen - 1;
    dat[k].a = newnum;
    while(k > 0) {
      k = (k - 1) / 2;
      dat[k].a = min(dat[k * 2 + 1].a, dat[k * 2 + 2].a);
    }
    return 1;
  }
  bool update2(int k, pair<long long, long> newnum) {
    k += sizen - 1;
    dat[k].a = newnum;
    while(k > 0) {
      k = (k - 1) / 2;
      dat[k].a = max(dat[k * 2 + 1].a, dat[k * 2 + 2].a);
    }
    return 1;
  }

  // "go down" process
  // return min number in [a,b)
  // pick(a,b,0,0,sizen)
  pair<long long, long long> pick1(int a, int b, int k = 0,
                                   int l = 0, int r = -1) {
    if(r == -1) r = sizen;
    // [l,r)[a,b) or [a,b)[l,r)
    if(r <= a || b <= l) return maxint;
    // [a,[l,r),b)
    if(a <= l && r <= b) return dat[k].a;
    // else
    pair<long long, long long> nowl, nowr;
    int nextlr = k * 2 + 1, med = (l + r) / 2;
    nowl = pick1(a, b, nextlr, l, med);
    nowr = pick1(a, b, nextlr + 1, med, r);
    return min(nowl, nowr);
  }
  pair<long long, long long> pick2(int a, int b, int k = 0,
                                   int l = 0, int r = -1) {
    if(r == -1) r = sizen;
    // [l,r)[a,b) or [a,b)[l,r)
    if(r <= a || b <= l) return minint;
    // [a,[l,r),b)
    if(a <= l && r <= b) return dat[k].a;
    // else
    pair<long long, long long> nowl, nowr;
    int nextlr = k * 2 + 1, med = (l + r) / 2;
    nowl = pick2(a, b, nextlr, l, med);
    nowr = pick2(a, b, nextlr + 1, med, r);
    return max(nowl, nowr);
  }
};

RMQ rmq[2];
long long n, now = 0, sum = 0;
vector<long long> a;
long long memo[100005][2] = {0};

long long solve();

int main() {
  cin >> n;
  for(int i = 0; i < 2; ++i) rmq[i] = RMQ(i, n + 1);
  for(int i = 0; i < 3; ++i)
    for(long long j = 0; j < n; ++j) {
      long long x;
      cin >> x;
      if(i == 0)
        rmq[0].update1(j, make_pair(x, j));
      else if(i == 1)
        a.push_back(x);
      else
        rmq[1].update2(j, make_pair(x, j));
      if(i == 0) sum += x;
      if(i == 2) sum -= x;
    }
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long ans = 0;
  for(int i = 0; i < n; ++i) {
    if(i != 0) memo[i][0] += memo[i - 1][0];
    pair<long long, long long> now = rmq[0].pick1(0, n);
    if(a[i] > now.first) {
      memo[i][0] += a[i] - now.first;
      now.first = a[i];
      rmq[0].update1(now.second, now);
    }
  }
  for(int i = 0; i < n; ++i) {
    if(i != 0) memo[i][1] += memo[i - 1][1];
    pair<long long, long long> now = rmq[1].pick2(0, n);
    if(a[n - 1 - i] < now.first) {
      memo[i][1] += now.first - a[n - 1 - i];
      rmq[1].update2(now.second,
                     make_pair(a[n - 1 - i], now.second));
    }
  }
  ans = max(memo[n - 1][0], memo[n - 1][1]);
  for(int i = 0; i < n - 1; ++i) {
    ans = max(ans, memo[i][0] + memo[n - 2 - i][1]);
  }
  return ans + sum;
}