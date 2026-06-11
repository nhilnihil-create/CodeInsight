#include<iostream>
#include<string>
using namespace std;
int main () {
  string S;
  cin >> S;
  int N = (int)S.size();
  if (N >= 4 && S[0] == 'Y' && S[1] == 'A' && S[2] == 'K' && S[3] == 'I') {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}