#include <bits/stdc++.h>
using namespace std;

int	main()
{
  string	s;
  int		begin, end, i = 0;
  
  cin >> s;
  for (; i < s.size(); i++)
  {
    if (s.at(i) == 'A')
    {
      begin = i;
      break;
    }
  }
  for(; i < s.size(); i++)
  {
    if (s.at(i) == 'Z')
      end = i;
  }
  cout << end - begin + 1 << endl;
  return (0);
}