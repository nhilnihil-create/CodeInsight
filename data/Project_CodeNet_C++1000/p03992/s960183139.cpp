#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s; cin >> s;
  string s1 = s.substr( 0, 4 );
  string s2 = s.substr( 4 );
  cout << s1 << " " << s2 << endl;
  return ( 0 );
}
