#include<iostream>
#include<string>
int main(void) {
	std::string str;
	std::cin >> str;
	str.at(5) = ' ';
	str.at(13) = ' ';
	std::cout << str << std::endl;
	system("pause");
}