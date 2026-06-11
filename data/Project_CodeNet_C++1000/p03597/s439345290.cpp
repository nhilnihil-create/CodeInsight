#include <iostream>
#include <math.h>

int main() {
	double DDblCulCells, DDblAllCells, DDblWhiteCells;
	double DDblBlackCells;

	std::cin >> DDblCulCells >> DDblWhiteCells;

	DDblAllCells = pow(DDblCulCells, 2);

	DDblBlackCells = DDblAllCells - DDblWhiteCells;

	std::cout << DDblBlackCells << std::endl;
}