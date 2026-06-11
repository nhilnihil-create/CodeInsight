#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

string Sa, Sb, Sc;

int main() {
  cin >> Sa >> Sb >> Sc;

  int turn = 'a';
  int a, b, c;
  a = b = c = 0;
  while (true) {
    switch (turn) {
      case 'a':
        if (a == Sa.size()) {
          cout << "A" << endl;
          goto end;
        }
        turn = Sa[a++];
        break;
      case 'b':
        if (b == Sb.size()) {
          cout << "B" << endl;
          goto end;
        }
        turn = Sb[b++];
        break;
      case 'c':
        if (c == Sc.size()) {
          cout << "C" << endl;
          goto end;
        }
        turn = Sc[c++];
        break;
    }
  }

end:
  return 0;
}
