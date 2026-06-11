#include <iostream>
#include <string>

char find_last_word(std::string A)
{
  char last_word;
  for(int i = 0; A[i] != NULL; i++)
  {
    last_word = A[i];
  }
  
  return last_word;
}

int main()
{
  std::string A, B, C, result = "YES";
  std::cin >> A >> B >> C;
  
  if(find_last_word(A) != B[0])
  {
    result = "NO"; 
  }
  else if(find_last_word(B) != C[0])
  {
    result = "NO";
  }
  
  std::cout << result;
  return 0;
}