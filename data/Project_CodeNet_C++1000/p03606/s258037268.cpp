#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  cin >> N;
  int l[N], r[N];
  rep(i,N) cin >> l[i] >> r[i];

  int sum = 0;
  rep(i,N){
    sum += r[i] - l[i] + 1;
  }
  cout << sum << endl;
}
