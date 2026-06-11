#include <bits/stdc++.h>
using namespace std;

int	main()
{
  string	s, t;
  
  cin >> s;
  for (int i = 0; i < s.size(); i += 2)
    t += s.at(i);
  cout << t << endl;
  return (0);
} 