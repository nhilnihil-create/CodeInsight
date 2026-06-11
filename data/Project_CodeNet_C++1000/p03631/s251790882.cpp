#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  string N;
  cin >> N;
  
  if (N[0] == N[2]) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
