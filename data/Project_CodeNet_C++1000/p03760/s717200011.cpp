#include <iostream>

using namespace std;

int main() {
  string O, E;
  cin >> O >> E;

  for (size_t i = 0; i != O.size()+E.size(); ++i) {
    cout << (i%2? E[i/2] : O[i/2]);
  }
  cout << endl;
  
  return 0;
}
