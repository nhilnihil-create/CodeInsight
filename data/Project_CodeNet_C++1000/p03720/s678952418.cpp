#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) { // n が 0 になるまで
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  vector<int> b(m);
  vector<int> sum(n);
  rep(i,m){
    cin >> a.at(i) >> b.at(i);
    sum.at(a.at(i)-1)++;
    sum.at(b.at(i)-1)++;
  }
    rep(i,n) cout << sum.at(i) << endl;
}