#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>

int main() {
	int N=0;
	int K=0;
	int X=0;
	int Y=0;
	std::cin >>N>>K>>X>>Y;

	int total=0;

if (N>=K)
{
		total=K*X+(N-K)*Y;
	
}else
{
	total=N*X;
		
}


std::cout << total << std::endl;

return 0;


}