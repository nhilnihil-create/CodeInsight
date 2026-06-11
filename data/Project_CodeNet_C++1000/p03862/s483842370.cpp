#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  long long N, x;
  cin >> N >> x;
  vector<long long> a(N);
  for(int i = 0; i < N; i++) cin >> a[i];
  long long ans = 0;
  for(int i = 0; i < N-1; i++){
    long long sum = a[i] + a[i+1];
    ans += max((long long)0, sum - x);
    if(sum - x > 0){
      a[i+1] -= min(a[i+1], sum - x);
    }
  }
  cout << ans <<endl;
}
