#include <bits/stdc++.h>
using namespace std;

// 1-indexed
template <class T>
struct BIT {
  vector<T> lst;
  int treesize;
  // constructor
  BIT(int newn = 0) {
    treesize = newn;
    lst.resize(treesize + 1);
    for(int i = 0; i <= treesize; ++i) lst[i] = 0;
  }
  // a_place += num
  bool add(int place, T num) {
    while(place <= treesize) {
      lst[place] += num;
      place += place & -place;
    }
    return 1;
  }
  // add wide ver.(add num between l and r)
  bool addw(int left, int right, T num) {
    while(left <= right && left >= 1 && right <= treesize)
      add(left++, num);
    return 1;
  }
  // sum between [1,place]
  T calcsum(int place) {
    T answer = 0;
    while(place > 0) {
      answer += lst[place];
      place -= place & -place;
    }
    return answer;
  }
  // sum [l,r]
  T calcsumw(int left, int right) {
    return calcsum(right) - calcsum(left - 1);
  }
};

long long n, k;
vector<long long> a, sum;
map<long long, long long> mp;
BIT<long long> bit;

long long solve();

int main() {
  cin >> n >> k;
  a.resize(n);
  for(int i = 0; i < n; ++i) cin >> a[i];
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long ans = 0;
  for(int i = 0; i < n; ++i) a[i] -= k;
  sum.resize(n + 1);
  for(int i = 0; i < n; ++i) sum[i + 1] = sum[i] + a[i];
  sort(sum.begin(), sum.end());
  sum.erase(unique(sum.begin(), sum.end()), sum.end());
  for(int i = 0; i < sum.size(); ++i) mp[sum[i]] = i + 1;
  bit = BIT<long long>(n + 1);
  long long nsum = 0;
  bit.add(mp[0], 1);

  for(int i = 0; i < n; ++i) {
    nsum += a[i];
    auto it = upper_bound(sum.begin(), sum.end(), nsum);
    if(it != sum.begin()) ans += bit.calcsum(mp[*(--it)]);
    bit.add(mp[nsum], 1);
  }
  return ans;
}