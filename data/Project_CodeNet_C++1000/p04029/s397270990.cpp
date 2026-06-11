#include <iostream>

int main()
{
    int a, idx, num;
	idx = 0;
  	num = 0;
    std::cin >> a;
  
  
  	while(idx < a) {
      idx++;
      num += idx;
    }

    std::cout << num << std::endl;
}