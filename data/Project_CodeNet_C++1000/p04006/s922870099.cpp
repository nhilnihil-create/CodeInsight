#include <bits/stdc++.h>
using namespace std;

int N;long long x;long long base=1000000005LL;

int main() {
  cin >> N >> x;
  vector<long long> A(N);
  for (int i=0;i<N;i++) cin >> A[i];
  vector<vector<long long>> T(N,vector<long long>(N,0LL));
  for (int i=0;i<N;i++) {
    for (int j=0;j<N;j++) {
      if (j==0) {
        T[i][j]=A[i];
      }
      else {
        T[i][j]=min(T[i][j-1],A[(i-j+N)%N]);
      }
    }
  }
  long long min_s=2000000000000005LL;
  for (int i=0;i<N;i++) {
    long long ss=i*x;
    for (int j=0;j<N;j++) {
      ss+=T[j][i];
    }
    min_s=min(min_s,ss);
  }
  cout << min_s << endl;
}