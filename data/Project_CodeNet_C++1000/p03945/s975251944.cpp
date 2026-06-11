#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string S;
  cin >> S;
  cout << unique(begin(S),end(S)) - begin(S) - 1 << endl;
}
