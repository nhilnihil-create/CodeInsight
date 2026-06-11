#include <iostream>
#include <string>

int main(){
	std::string s, begin, end;
	
	std::cin >> s;

	begin = s.substr(0, 1);
	end = s.substr(s.size()-1, 1);

	std::cout << begin << s.size()-2 << end << std::endl;

	return 0;
}
