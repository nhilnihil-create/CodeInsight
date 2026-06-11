#include <iostream>
 
int main()
{  
  int W, a, b, move_length;
  std::cin >> W >> a >> b;

  int a_end = a + W;
  int b_end = b + W;
  
  if((a <= b && b <= a_end) || (a <= b_end && b_end <= a_end))
  {
     move_length = 0;
  }
  else
  {
    if(a_end < b)
    {
      move_length = b - a_end;
    }
    else
    {
      move_length = a - b_end;    
    }
  }
  
  std::cout << move_length;
  return 0;
}