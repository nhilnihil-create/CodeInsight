#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B;
  cin >> A >> B;
  string answer = (A + B) < 10 ? to_string(A + B) : "error";
  cout << answer << endl;
}
