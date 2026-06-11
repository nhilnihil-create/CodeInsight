#include <bits/stdc++.h>
using namespace std;

long long N;
#define MAX_B 39
set<int> S;
int M, F;
deque<int> R;

int main() {
  cin >> N;
  for(int i = 0; i <= MAX_B; ++i) {
    if((N + 1) & (1LL << i)) S.insert(i);
  }
  int M = *S.rbegin(), F = M;
  for(int i = M - 1; i >= 0; --i) R.push_back(i);
  for(int i = M - 1; i >= 0; --i) {
    R.push_back(i);
    if(S.count(i)) {
      R.push_back(F); R.push_front(F); ++F;
    }
  }
  cout << R.size() << endl;
  for(int i = 0; i < (int)R.size(); ++i) {
    cout << (i == 0 ? "" : " ") << R[i] + 1;
  }
  cout << endl;
  return 0;
}
