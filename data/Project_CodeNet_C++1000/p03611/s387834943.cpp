#include <bits/stdc++.h>
#define M 100000
using namespace std;
int main() {
  int N,answer=0,a;
  map<int,int> b;
  for (cin >> N; N; b[a]++, N--) {
    cin >> a;
  }
  for (int i = 0; i <= M; i++) {
    answer = max(answer,b[i]+b[i-1]+b[i+1]);
  }
  cout << answer;
}