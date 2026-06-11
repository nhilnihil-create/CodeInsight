#include <bits/stdc++.h>
using namespace std;

int	main()
{
  string	s;
  
  cin >> s;
  s = s.at(0) + to_string(s.size() - 2) + s.at(s.size() - 1);
  cout << s << endl;
  return (0);
}