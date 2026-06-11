#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i=0; i<N; i++) cin >> A[i];
  int res = 0;
  for (int i=0; i<N; i++) {
    while (i+1<N&&A[i]==A[i+1]) i++;
    if (i+1<N&&A[i]<A[i+1]) {
      while (i+1<N&&A[i]<=A[i+1]) i++;
    }
    else if (i+1<N&&A[i]>A[i+1]) {
      while (i+1<N&&A[i]>=A[i+1]) i++;
    }
    res++;
  }
  cout << res << endl;
}