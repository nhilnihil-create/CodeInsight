#include <iostream>
#include <string>

int check_length(std::string S)
{
  int length = 0;
  
  while(S[length] != NULL)
  {
    length++;
  }
  
  return length;
}

bool check_even_string(std::string S, int length)
{
  for(int i = 0; i < length / 2; i++)
  {
    if(S[i] != S[(length / 2) + i])
    {
      return false;
    }
  }

  return true;
}

int main()
{
  std::string S;
  int length;
  std::cin >> S;
  
  length = check_length(S);
  
  for(int i = length - 1; i > 0; i--)
  {
    if(i % 2 != 0)
    {
      continue;
    }

    if(check_even_string(S, i) == true)
    {
      length = i;
      break;
    }
  }
  
  std::cout << length;
  return 0;
}