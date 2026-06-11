#include <iostream>

using namespace std;

int main() {
  string sa, sb, sc;
  int ap = 0, bp = 0, cp = 0;
  cin >> sa >> sb >> sc;

  char c = 'a';

  while (true) {
    if (c == 'a') {
      if (sa.size() <= ap) {
        cout << 'A' << endl;
        break;
      }
      c = sa[ap++];
    } else if (c == 'b') {
      if (sb.size() <= bp) {
        cout << 'B' << endl;
        break;
      }
      c = sb[bp++];
    } else if (c == 'c') {
      if (sc.size() <= cp) {
        cout << 'C' << endl;
        break;
      }
      c = sc[cp++];
    }
  }

  return 0;
}
