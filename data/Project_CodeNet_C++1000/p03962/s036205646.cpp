#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  std::unordered_set<int> s;

  int in;
  cin >> in;
  s.insert(in);
  cin >> in;
  s.insert(in);
  cin >> in;
  s.insert(in);

  cout << s.size() << endl;
  
  return 0;
}
