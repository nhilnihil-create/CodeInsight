#include <iostream>
#include <string>

int main()
{
  int moji;
  bool match;
  std::string S, result;
  std::cin >> S;
  
  for(int i = 97; i <= 122; i++)
  {
    match = false;
    moji = i;

    for(int k = 0; S[k] != NULL; k++)
    {
      if((int)S[k] == i)
      {
        match = true;
        break;
      }
    }
    
    if(match == false)
    {
      break;
    }
  }

  if(moji == 122 && match == true)
  {
    result = "None";
  }
  else
  {
    result = moji;
  }
  
  std::cout << result;
  return 0;
}