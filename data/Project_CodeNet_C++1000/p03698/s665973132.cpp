#include <iostream>
#include <string>

int main()
{
  std::string S, result = "yes";
  std::cin >> S;
  
  for(int i = 0; S[i] != NULL; i++)
  {
    for(int k = i + 1; S[k] != NULL; k++)
    {
      if(S[i] == S[k])
      {
        result = "no";
      }
    }
  }
  
  std::cout << result;  
  return 0;
}