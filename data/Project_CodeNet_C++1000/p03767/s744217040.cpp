#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> p(3*N);
  for (int i=0; i<3*N; i++) cin >> p[i];
  sort(p.begin(), p.end(), greater<int>());
  long sum=0;
  for (int i=1; i<2*N; i+=2) sum += p[i];
  cout << sum << endl;
}