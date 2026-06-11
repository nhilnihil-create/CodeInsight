#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

int main()
{
  int n;
  int count[100000] = {};
  cin>>n;
  int m1;
  rep(i, n) {
    cin>>m1;
    count[m1]++;
    if (m1 -1 >= 0) {
      count[m1 -1] ++;
    }
    if(m1 +1 < 100000) {
      count[m1 +1] ++;
    }
  }

  int max = 0;
  rep(i, 100000) {
    if (count[i] > max) {
      max = count[i];
    }
  }
  cout << max << endl;
  return 0;
}