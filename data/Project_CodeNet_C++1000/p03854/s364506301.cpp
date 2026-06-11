#include <iostream>
#include <string>

int main()
{
  std::string S, result = "YES";
  std::string str_pattern[4] = {"dream", "dreamer", "erase", "eraser"};
  std::cin >> S;

  int end = S.length();
  while(end > 0)
  {
    bool match = false;
    for(int i = 0; i < 4; i++)
    {
      int start = end - str_pattern[i].length();
      if(start < 0)
      {
        continue;
      }
      
      if(S.compare(start,  str_pattern[i].length(), str_pattern[i]) == 0)
      {
        end -= str_pattern[i].length();
        match = true;
        break;
      }
    }
    
    if(match == false)
    {
      result = "NO";
      break;
    }
  }
  
  std::cout << result;
  return 0;
}