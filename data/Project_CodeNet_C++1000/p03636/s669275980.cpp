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
 
int main()
{
  std::string S;
  int length;
  std::cin >> S;
  
  length = check_length(S);

  std::cout << S[0] << length - 2 << S[length -1];
  return 0;
}