#include <iostream>

int main() {
  int a[3];
  int c5(0), c7(0);
  std::cin >> a[0] >> a[1] >> a[2];
  for (int i=0; i<3; i++)
  {
    if (a[i] == 5) c5++;
    else if(a[i] == 7) c7++;
  }
  if (c5 == 2 || c7 == 1) std::cout << "YES" << std::endl;
  else std::cout << "NO" << std::endl;
  return 0;
}