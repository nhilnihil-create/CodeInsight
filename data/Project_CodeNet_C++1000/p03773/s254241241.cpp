#include <bits/stdc++.h>
#include <deque>

using namespace std;

template <typename T> void printVector(vector<T> vector) {
  if (vector.size() > 0)
    cout << vector[0];
  for (auto it = ++vector.begin(); it != vector.end(); it++)
    cout << " " << *it;
  cout << ";\n";
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int A, B;
  cin >> A >> B;

  A += B;
  A %= 24;

  cout << A << endl;

  return EXIT_SUCCESS;
}
