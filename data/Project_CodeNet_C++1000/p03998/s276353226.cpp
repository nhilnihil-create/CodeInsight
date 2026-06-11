#include <bits/stdc++.h>
using namespace std;

char winner;
vector<string> deck(3);

void game(int turn, vector<int> np) {
  if (deck[turn][np[turn]] == '\0') {
    winner = turn + 'A';
  } else {
    np[turn] += 1;
    game(deck[turn][np[turn] - 1] - 'a', np);
  }
}

int main() {
  cin >> deck[0] >> deck[1] >> deck[2];
  game(0, {0, 0, 0});
  cout << winner;
}
