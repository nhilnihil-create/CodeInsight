#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  vector<int> B = A;
  sort(B.begin(), B.end());
  map<int, int> mp;
  for (int i = 0; i < N; i++){
    mp[B[i]] = i;
  }
  for (int i = 0; i < N; i++){
    A[i] = mp[A[i]];
  }
  int ans = 0;
  for (int i = 0; i < N; i += 2){
    if (A[i] % 2 == 1){
      ans++;
    }
  }
  cout << ans << endl;
}