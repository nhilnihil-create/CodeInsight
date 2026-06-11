#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  string X;
  cin >> X;
  int N = X.size();
  vector<char> answer;
  rep(i, N) {
    if (X[i] == 'S') {
      answer.emplace_back('S');
    } else if (X[i] == 'T') {
      if (answer.empty() || answer.back() == 'T')
        answer.emplace_back('T');
      else
        answer.pop_back();
    }
  }
  cout << answer.size() << endl;
  return 0;
}