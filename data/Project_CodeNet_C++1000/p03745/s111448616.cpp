#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,N) cin >> A[i];

  int ans=0;
  for (int i=0; i<N; i++) {
    while(i+1 < N && A[i] == A[i+1]) i++;

    if (i+1 < N && A[i] < A[i+1]) {
      while(i+1 < N && A[i] <= A[i+1]) i++;
    }
    else if (i+1 < N && A[i] > A[i+1]) {
      while(i+1 < N && A[i] >= A[i+1]) i++;
    }
    ans++;
  }
  cout << ans << endl;
}