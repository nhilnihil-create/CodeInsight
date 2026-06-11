#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N,A,answer=0;
  map<int,int> B;
  for (cin >> N; N; B[A]++, N--) {
    cin >> A;
  }
  vector<int> lengths;
  for (auto p : B) {
    if (p.second >= 4) {
      answer = max(answer,1ll*p.first*p.first);
    }
    if (p.second >= 2) {
      lengths.push_back(p.first);
    }
  }
  if (lengths.size() >= 2) {
    answer = max(answer,1ll*lengths.back()*lengths[lengths.size()-2]);
  }
  cout << answer;
}