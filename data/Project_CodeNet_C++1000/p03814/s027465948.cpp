#include <iostream>

int main()
{
  std::string s;
  std::cin >> s;

  int pos_a = 0;
  int pos_z = s.size() - 1;
  while(s[pos_a] != 'A') {
    pos_a++;
  }
  while(s[pos_z] != 'Z') {
    pos_z--;
  }

  std::cout << pos_z - pos_a + 1 << std::endl;

  return 0;
}
