#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  vector<queue<char>> vq(3);
  for (int i = 0; i < 3; i++)
  {
    cin >> s;
    for (int j = 0; j < s.size(); j++)
      vq.at(i).push(s[j]);
  }
  char turn = 0;
  while (true)
  {
    char nxt_turn = vq[turn].front() - 'a';
    vq[turn].pop();
    turn = nxt_turn;
    if (vq[turn].empty())
      break;
  }
  cout << (char)('A' + turn) << endl;
}
