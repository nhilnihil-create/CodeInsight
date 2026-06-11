#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,answer=0;
  cin >> N;
  int a[N];
  map<int,int> b;
  for (int i = 0; i < N; b[a[i++]]++) {
    cin >> a[i];
  }
  for (int i = 0; i < N; i++) {
    answer = max(answer,b[a[i]]+b[a[i]-1]+b[a[i]+1]);
  }
  cout << answer;
}