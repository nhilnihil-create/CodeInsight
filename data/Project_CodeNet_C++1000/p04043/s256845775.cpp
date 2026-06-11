#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>

int main() {
	int A=0;
	int B=0;
	int C=0;

std::cin >>A>>B>>C;

if ((A==5&&B==5&C==7)||(A==5&&B==7&C==5)||(A==7&&B==5&C==5))
{
	std::cout << "YES" << std::endl;
	return 0;
}

std::cout << "NO" << std::endl;


	return 0;
}