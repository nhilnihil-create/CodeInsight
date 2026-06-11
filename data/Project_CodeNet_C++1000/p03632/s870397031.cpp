#include <iostream>
using namespace std;

int main()
{
  int res, alice_start, alice_end, bob_start, bob_end;

  cin >> alice_start >> alice_end >> bob_start >> bob_end;

  if (alice_end < bob_start || alice_start > bob_end) res = 0;
  else if (alice_start < bob_start && bob_end < alice_end) res = bob_end - bob_start;
  else if (bob_start <= alice_start && alice_end <= bob_end) res = alice_end - alice_start;
  else if (bob_start < alice_start && bob_end < alice_end) res = bob_end - alice_start;
  else res = alice_end - bob_start;
  cout << res << endl;
  return 0;
}
