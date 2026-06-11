#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  for (int i = 0; i < N; i++){
    a[i] -= K;
  }
  vector<long long> S(N + 1, 0);
  for (int i = 0; i < N; i++){
    S[i + 1] = S[i] + a[i];
  }
  vector<long long> S2 = S;
  sort(S2.begin(), S2.end());
  S2.erase(unique(S2.begin(), S2.end()), S2.end());
  int cnt = S2.size();
  map<long long, int> mp;
  for (int i = 0; i < cnt; i++){
    mp[S2[i]] = i;
  }
  for (int i = 0; i <= N; i++){
    S[i] = mp[S[i]];
  }
  long long ans = 0;
  vector<int> BIT(cnt + 1, 0);
  for (int i = 0; i <= N; i++){
    int j;
    j = S[i] + 1;
    while (j > 0){
      ans += BIT[j];
      j -= j & -j;
    }
    j = S[i] + 1;
    while (j <= cnt){
      BIT[j]++;
      j += j & -j;
    }
  }
  cout << ans << endl;
}