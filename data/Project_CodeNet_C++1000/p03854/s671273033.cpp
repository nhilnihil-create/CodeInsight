#include<iostream>
#include<string>
using namespace std;

int main()
{
  string s;
  cin >> s;
  
  int tail = s.size();
  
  while (tail > 0)
  {
    if (tail >= 7 && s.substr(tail - 7, 7) == "dreamer")
    {
      tail -= 7;
    }
    else if (tail >= 6 && s.substr(tail - 6, 6) == "eraser")
    {
      tail -= 6;
    }
    else if (tail >= 5 && s.substr(tail - 5, 5) == "dream")
    {
      tail -= 5;
    }
    else if (tail >= 5 && s.substr(tail - 5, 5) == "erase")
    {
      tail -= 5;
    }
    else
    {
      cout << "NO";
      return 0;
    }
  }
  
  cout << "YES";
  return 0;
}
