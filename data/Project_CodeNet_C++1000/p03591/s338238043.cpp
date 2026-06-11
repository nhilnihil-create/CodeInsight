#include <iostream>
using namespace std;
int main()
{
  string S;
  cin >> S;
  int N = S.length();
  if (4 <= N && S[0] == 'Y' && S[1] == 'A' && S[2] == 'K' && S[3] == 'I')
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}