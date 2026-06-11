#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int A, B;
  cin >> A >> B;
  cout << ((A + B) % 24) << "\n";
  return 0;
}
