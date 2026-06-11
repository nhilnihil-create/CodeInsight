#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, T;
  cin >> N >> T;
  vector<long long> A(N);
  for (int i=0; i<N; i++) cin >> A[i];
  map<long long, long long> mp;
  long long maxA = A[N-1];
  long long maxdif = 0;
  int count = 0;
  for (int i=N-2; i>=0; i--){
    if (maxdif==maxA-A[i]){
      count++;
    } else if (maxdif < maxA-A[i]){
      count = 1;
      maxdif = maxA-A[i];
    }
    maxA = max(maxA, A[i]);
  }
  cout << count << endl;
}
