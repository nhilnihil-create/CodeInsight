#include <bits/stdc++.h>
using namespace std;

int main() {
  string sa, sb, sc;
  cin >> sa >> sb >> sc;
  char next_turn = 'a', winner;

  while(true) {
    if(next_turn == 'a') {
      if(sa.size() == 0) {
        winner = 'A';
        cout << winner << endl;
        return 0;
      }
      next_turn = sa[0];
      sa.erase(0, 1);
    }
    else if(next_turn == 'b') {
      if(sb.size() == 0) {
        winner = 'B';
        cout << winner << endl;
        return 0;
      }
      next_turn = sb[0];
      sb.erase(0, 1);
    }
    else if(next_turn == 'c') {
      if(sc.size() == 0) {
        winner = 'C';
        cout << winner << endl;
        return 0;
      }
      next_turn = sc[0];
      sc.erase(0, 1);
    }
  }
}