#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  int N, A, B;
  cin >> N >> A >> B;
  string S;
  cin >> S;
  int winner = 0;
  int foreigner_winner = 0;
  for (int i=0; i<S.size(); ++i) {
    if (S[i] == 'a' && winner < A+B) {
        cout << "Yes" << endl;
        winner++;
    } else if (S[i] == 'b' && winner < A+B && foreigner_winner < B) {
        cout << "Yes" << endl;
        winner++;
        foreigner_winner++;
    } else {
        cout << "No" << endl;
    }
  }
  return 0;
}
