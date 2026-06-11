#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  vector<int> p(N);
  for (int i = 0; i < N; i++){
    p[a[i] - 1] = i;
  }
  set<int> pos;
  pos.insert(-1);
  pos.insert(N);
  long long ans = 0;
  for (int i = 0; i < N; i++){
    long long L = p[i] - *prev(pos.lower_bound(p[i]));
    long long R = *(pos.lower_bound(p[i])) - p[i];
    ans += L * R * a[p[i]];
    pos.insert(p[i]);
  }
  cout << ans << endl;
}