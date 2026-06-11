#include <iostream>
#include <string>
using namespace std;
 
int main() {
  string S,ans;
  cin >> S;
  int S_len = S.size();
  string Str = to_string(S_len-2);
  cout << S.at(0) << Str << S.at(S_len-1) << endl;
}