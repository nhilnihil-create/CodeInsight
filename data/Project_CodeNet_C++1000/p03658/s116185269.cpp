#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int K;
  cin >> N >> K;
  
  vector<int> a(N);
  for(int i=0; i<N; ++i) {
    cin >> a[i];
  }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
  int ans=0;
  for(int i=0; i<K; ++i) {
    ans += a[i];
  }
  cout << ans << endl;
  return 0;
}
    
  