#include <iostream>
#include <algorithm>
 
int main ( void ) {
 
	int n, m;
	std::cin >> n >> m;
 
	std::vector < std::string > data( n );
	for ( std::string& str : data ) {
		std::cin >> str;
	}
 
	sort ( data.begin(), data.end() );
	for ( const std::string& str : data ) {
		std::cout << str;
	}
	std::cout << std::endl;
 
	return 0;
}