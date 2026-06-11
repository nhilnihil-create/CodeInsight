#include <iostream>
#include <stack>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  int N;
  cin >> N;
  string S;
  cin >> S;

  stack<char> blacket;
  string pre;
  int start = 0;
  while (start < N && S[start] == ')') {
    pre += '(';
    start++;
  }

  string post;
  int end = N - 1;
  while (0 <= end && S[end] == '(') {
    post += '(';
    end--;
  }

  int count = 0;
  for (int i = start; i <= end; ++i) {
    if (S[i] == '(')
      count++;
    else {
      if (count == 0)
        pre += '(';
      else
        count--;
    }
  }
  rep(i, start) pre += ')';
  rep(i, count) post += ')';
  rep(i, N - end - 1) post += ')';

  cout << pre + S.substr(start, end - start + 1) + post << endl;
  return 0;
}
