#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a.at(i);
  map<int, int> A;
  for (int i = 0; i < N; i++) A[a.at(i)]++;
  
  int ans = 0;
  for (int X = 1; X < 100000; X++){
    int sum = 0;
    if(A.count(X - 1)) sum += A.at(X - 1);
    if(A.count(X)) sum += A.at(X);
    if(A.count(X + 1)) sum += A.at(X + 1);
    ans = max(ans, sum);
  }
  
  cout << ans << endl;
}
