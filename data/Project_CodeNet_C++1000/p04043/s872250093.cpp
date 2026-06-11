#include <iostream>

int main()
{
    int a, b, c;
	std::string res;
    std::cin >> a >> b >> c;
	if( (a*b==25 && c == 7) || (a*c==25 && b == 7)|| (b*c==25 && a == 7) ) {
      res = "YES";
    } else {
      res = "NO";
    }
    std::cout << res << std::endl;
}