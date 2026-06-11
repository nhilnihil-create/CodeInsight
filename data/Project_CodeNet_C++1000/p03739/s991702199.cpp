#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int64_t pcount = 0, mcount = 0;//p,a[0]を負から始めるm,a[0]を正から始める
  int sump = 0, summ = 0;
  for (int i = 0; i < n; i++) {
    sump += a[i];
    summ += a[i];
    if(i % 2 == 0) {
      if(summ >= 0) {
        mcount += 1 + summ;
        summ = -1;
      }
      if(sump <= 0) {
        pcount += 1 - sump;
        sump = 1;
      }
    }else {//添え字奇数
      if(summ <= 0) {
        mcount += 1 - summ;
        summ = 1;
      }
      if(sump >= 0) {
        pcount += 1 + sump;
        sump = -1;
      }
    }
  }
  cout << min(pcount, mcount);
}