#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
  string S; cin >> S;
  regex re(R"(^YAKI.*)");
  if (regex_match(S, re)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}