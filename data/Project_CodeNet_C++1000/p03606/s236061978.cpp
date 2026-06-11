#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  int answer = 0;
  rep(i, N){
    int l, r;
    cin >> l >> r;
    answer += (r - l + 1);
  }
  cout << answer << endl;
  return 0;
}