#include<iostream>
#include<string>
int main(void) {
	int sx, sy, tx, ty;
	std::cin >> sx >> sy >> tx >> ty;
	int dx = tx - sx;
	int dy = ty - sy;
	for (int L1 = 0; L1 < dx; L1++)
		std::cout << "R" ;
	for (int L2 = 0; L2 < dy; L2++)
		std::cout << "U" ;
	for (int L1 = 0; L1 < dx; L1++)
		std::cout << "L" ;
	for (int L2 = 0; L2 < dy; L2++)
		std::cout << "D" ;

	std::cout << "D" ;
	for (int L1 = 0; L1 < dx + 1; L1++)
		std::cout << "R" ;
	for (int L2 = 0; L2 < dy + 1; L2++)
		std::cout << "U" ;
	std::cout << "L" ;

	std::cout << "U" ;
	for (int L1 = 0; L1 < dx + 1; L1++)
		std::cout << "L" ;

	for (int L2 = 0; L2 < dy + 1; L2++)
		std::cout << "D" ;
	std::cout << "R" << std::endl;
	system("pause");
}