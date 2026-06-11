#include <iostream>
#include <string>

int length(std::string a)
{
  int i = 0;
  while(a[i] != NULL)
  {
    i++;
  }
  return i;
}

int main()
{
  std::string a, b, result = "EQUAL";
  std::cin >> a >> b;
  
  int a_length = length(a);
  int b_length = length(b);
  
  if(a_length > b_length)
  {
    result = "GREATER";
  }
  else if(a_length < b_length)
  {
    result = "LESS";    
  }
  else
  {
    for(int i = 0; a[i] != NULL && b[i] != NULL; i++)
    {
      if(a[i] > b[i])
      {
        result = "GREATER";        
        break;
      }
      else if(a[i] < b[i])
      {
        result = "LESS";    
        break;
      }
    }
  }

  std::cout << result;
  return 0;
}