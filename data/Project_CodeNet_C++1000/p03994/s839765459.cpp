#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s; cin >> s;
  long long K; cin >> K;

  for ( int i = 0; i < s.size(); ++i )
  {
    char tmp = s[i] - 'a';
    if ( ( tmp != 0 ) && ( tmp + K >= 26 ) )
    {
      K -= 26 - tmp;
      s[i] = 'a';
    }
  }
  s.back() = ( ( s.back() - 'a' ) + K ) % 26 + 'a';

  cout << s << endl;

  return ( 0 );
}
