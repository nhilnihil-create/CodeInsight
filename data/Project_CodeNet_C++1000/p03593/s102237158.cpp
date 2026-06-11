#include <iostream>
#include <map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int H, W;
  cin >> H >> W;
  vector<int> word(26, 0);
  rep(i, H) {
    rep(j, W) {
      char a;
      cin >> a;
      word[a - 'a']++;
    }
  }

  // H=5 W=7
  // a b c d c b a
  // e f g h g f e
  // i j k l k j i
  // e f g h g f e
  // a b c d c b a

  // H=4 W=7
  // a b c d c b a
  // e f g h g f e
  // e f g h g f e
  // a b c d c b a

  // H=4 W=6
  // a b c c b a
  // e f g g f e
  // e f g g f e
  // a b c c b a

  int g1 = ((H % 2) && (W % 2)) ? 1 : 0;
  int g2 = 0;
  if (W % 2) g2 += H / 2;
  if (H % 2) g2 += W / 2;
  int g4 = H / 2 * W / 2;
  // cout << "g1=" << g1 << " g2=" << g2 << " g4=" << g4 << endl;

  while (g1--) {
    rep(i, 26) {
      if ((word[i] % 4 == 1) || (word[i] % 4 == 3)) {
        word[i] -= 1;
        break;
      }
    }
  }

  while (g2--) {
    bool found = false;
    rep(i, 26) {
      if (word[i] % 4 == 2) {
        word[i] -= 2;
        found = true;
        break;
      }
    }
    if (found) continue;

    rep(i, 26) {
      if (word[i] != 0 && word[i] % 4 == 0) {
        word[i] -= 2;
        break;
      }
    }
  }

  while (g4--) {
    rep(i, 26) {
      if (word[i] != 0 && word[i] % 4 == 0) {
        word[i] -= 4;
        break;
      }
    }
  }

  rep(i, 26) {
    if (word[i] != 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
