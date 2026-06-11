#include<bits/stdc++.h>

using namespace std;

typedef long long int64;
const int INF = 1 << 29;

int main()
{
  int N, A[100000];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int64 ret = 0, toll = 1;
  for(int i = 0; i < N; i++) {
    auto get = (A[i] - 1) / toll;
    ret += get;
    if(toll == 1 || toll == A[i]) ++toll;
  }

  cout << ret << endl;
}