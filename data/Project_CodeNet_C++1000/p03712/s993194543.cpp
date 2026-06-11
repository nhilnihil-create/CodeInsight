#include <iostream>
#include <string>

int main()
{
  std::string picture[100];
  int H, W;
  std::cin >> H >> W;

  for(int i = 0; i < H; i++)
  {
    std::cin >> picture[i];
  }
  
  for(int i = 0; i < W + 2; i++)
  {
    std::cout << "#";  
  }
  std::cout << "\n";  
  
  for(int i = 0; i < H; i++)
  {
    std::cout << "#" << picture[i] << "#\n";
  }

  for(int i = 0; i < W + 2; i++)
  {
    std::cout << "#";  
  }
  std::cout << "\n";  
  
  return 0;
}