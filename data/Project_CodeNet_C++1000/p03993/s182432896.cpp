#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) {
    int a;
    cin >> a;
    A[i] = a - 1;
  }

  int answer = 0;
  rep(i, N) {
    if(A[A[i]] == i) ++ answer;
  }
  cout << answer / 2 << endl;
  return 0;
}
