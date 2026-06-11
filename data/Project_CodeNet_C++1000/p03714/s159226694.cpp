#include <bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<int> a(3 * n);
  for(int i = 0; i < 3 * n; i++) cin >> a[i];
  long long ans = -(1ll<<60);
  vector<long long> ma(3 * n);
  vector<long long> mi(2 * n + 1);
  {
    multiset<int> inb;
    long long sum = 0;
    for(int i = 2 * n; i < 3 * n; i++){
      inb.insert(a[i]);
      sum += a[i];
    }
    mi[2 * n] = sum;
    for(int i = 2 * n - 1; i >= 0; i--){
      inb.insert(a[i]); sum += a[i];
      sum -= *(--inb.end()); inb.erase(--inb.end());
      mi[i] = min(mi[i + 1], sum);
    }
    long long rsum = 0;
    multiset<pair<int,int> > by_v, by_p;
    for(int i = 2 * n - 1; i >= 0; i--){
      by_v.insert({a[i], i});
      by_p.insert({i, a[i]});
      rsum += a[i];
      if(i < n){
        auto worst = *by_v.begin(); by_v.erase(by_v.begin());
        rsum -= worst.first;
        by_p.erase({worst.second, worst.first});
      }
      if(i <= n){
        auto it = *(--by_p.end());
        ans = max(ans, rsum - mi[it.first + 1]);
      }
    }
  }
  {
    multiset<int> ina;
    long long sum = 0;
    for(int i = 0; i < n; i++){
      sum += a[i];
      ina.insert(a[i]);
    }
    ma[n - 1] = sum;
    for(int i = n; i < 3 * n; i++){
      ina.insert(a[i]); sum += a[i];
      sum -= *ina.begin(); ina.erase(ina.begin());
      ma[i] = max(sum, ma[i - 1]);
    }
    long long rsum = 0;
    multiset<pair<int,int> > by_p, by_v;
    for(int i = n; i < 3 * n; i++){
      by_v.insert({a[i], i});
      by_p.insert({i, a[i]});
      rsum += a[i];
      if(i >= 2 * n){
      	auto worst = *(--by_v.end()); by_v.erase(--by_v.end());
        rsum -= worst.first;
        by_p.erase({worst.second, worst.first});
      }
      if(i >= 2 * n - 1){
      	auto it = *by_p.begin();
        ans = max(ans, ma[it.first - 1] - rsum);
      }
    }
  }
  for(int i = n - 1; i < 2 * n; i++) ans = max(ans, ma[i] - mi[i + 1]);
  cout << ans << endl;
  return 0;
}
    
