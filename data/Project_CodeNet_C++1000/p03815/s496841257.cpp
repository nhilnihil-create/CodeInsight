#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("../data.txt");

long long x, moves;

int main() {

  cin >> x;
  moves += (1LL*x/11) * 2;
  moves += 2;
  if (x % 11 == 0) moves -= 2;
  else if (x%11 <= 6) moves -= 1;
  cout << moves;
  return 0;
}
